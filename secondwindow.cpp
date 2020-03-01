#include "secondwindow.h"
#include <QString>

//Makes the second window which will be able to recieve the signal from MainWindow
SecondWindow::SecondWindow(QWidget *parent)
    : QWidget(parent)
{
    this->setFixedSize(875,700);
    QPixmap bkgnd(":/main.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    setFocusPolicy(Qt::ClickFocus);

    QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    music = new QMediaPlayer(this);

    // button to turn on/off music
    mute = new QPushButton;
    QPixmap mutePix(":/music.png");
    mutePix = mutePix.scaled(102, 60, Qt::KeepAspectRatio, Qt::FastTransformation);
    QIcon muteIcon(mutePix);
    mute->setIcon(muteIcon);
    mute->setIconSize(mutePix.rect().size());
    mute->setFixedSize(mutePix.rect().size());

    // button to see sandwich recipes
    QPushButton* recipes = new QPushButton;
    QPixmap recipesPix(":/recipes.png");
    recipesPix = recipesPix.scaled(125, 60, Qt::KeepAspectRatio, Qt::FastTransformation);
    QIcon recipesIcon(recipesPix);
    recipes->setIcon(recipesIcon);
    recipes->setIconSize(recipesPix.rect().size());
    recipes->setFixedSize(recipesPix.rect().size());

    // button to go back to home screen
    homeScreen = new QPushButton;
    QPixmap homePix(":/home.png");
    homePix = homePix.scaled(100, 60, Qt::KeepAspectRatio, Qt::FastTransformation);
    QIcon homeIcon(homePix);
    homeScreen->setIcon(homeIcon);
    homeScreen->setIconSize(homePix.rect().size());
    homeScreen->setFixedSize(homePix.rect().size());

    // button will be in recipes screen
    QPushButton *backToGame = new QPushButton("Done");

    // 'Back' buttons on the win and lose pages
    backToHome1 = new QPushButton();
    backToHome1->setIcon(homeIcon);
    backToHome1->setIconSize(homePix.rect().size());
    backToHome1->setFixedSize(homePix.rect().size());
    connect(backToHome1, SIGNAL(clicked()),this,SLOT(goToSecondPage())); // RIGHT NOW, WHEN YOU WIN/LOSE YOU CAN ONLY EXIT TO THE GAME SCREEN, NOT THE HOME SCREEN

    backToHome2 = new QPushButton();
    backToHome2->setIcon(homeIcon);
    backToHome2->setIconSize(homePix.rect().size());
    backToHome2->setFixedSize(homePix.rect().size());
    connect(backToHome2, SIGNAL(clicked()),this,SLOT(goToSecondPage())); // RIGHT NOW, WHEN YOU WIN/LOSE YOU CAN ONLY EXIT TO THE GAME SCREEN, NOT THE HOME SCREEN

    title_space = new QHBoxLayout();
    play_space = new QGridLayout();
    sandwich_layout = new QGridLayout();

   /* QTimer* timer = new QTimer(this);
       connect(timer, SIGNAL(timeout()), this, SLOT(update()));
       timer->start(1000);*/

    QLabel* bread1 = new QLabel("White\nBread");
    QLabel* bread2 = new QLabel("Whole\nWheat\nBread");
    QLabel* bread3 = new QLabel("Pretzel\nBun");

    QLabel* cheese1 = new QLabel("American\nCheese");
    QLabel* cheese2 = new QLabel("Swiss\nCheese");
    QLabel* cheese3 = new QLabel("Vegan\nCheese");

    QLabel* meat1 = new QLabel("Turkey\nMeat");
    QLabel* meat2 = new QLabel("Steak");
    QLabel* meat3 = new QLabel("Impossible\nMeat");

    QLabel* veggies1 = new QLabel("Lettuce");
    QLabel* veggies2 = new QLabel("Peppers");
    QLabel* veggies3 = new QLabel("Spinach");

    text1 = new QLabel(" Welcome to Heck's Kitchen!");
    text1->setStyleSheet("QLabel { color : black }");
    health_text = new QLabel("      Health: "+ QString::number(health) );
    health_text->setStyleSheet("QLabel { color : black }");
    main_character = new Player;

    breadBin1 = new Bread_Bin(8,2, "White Bread");
    breadBin2 = new Bread_Bin(9,2, "Whole Wheat Bread");
    breadBin3 = new Bread_Bin(10,2, "Prezel Bun");

    cheeseBin1 = new Cheese_Bin(12,2, "American Cheese");
    cheeseBin2 = new Cheese_Bin(12,3, "Swiss Cheese");
    cheeseBin3 = new Cheese_Bin(12,4, "Vegan Cheese");

    meatBin1 = new Meat_Bin(12,5, "Turkey Meat");
    meatBin2 = new Meat_Bin(12,6, "Steak");
    meatBin3 = new Meat_Bin(12,7, "Immpossible Meat");

    veggieBin1 = new Veggie_Bin(6,6, "Lettuce");
    veggieBin2 = new Veggie_Bin(7,6, "Peppers");
    veggieBin3 = new Veggie_Bin(8,6, "Spinach");

    trash = new Bin(4, 1);

    //SET UP CUSTOMER
    customer1 = new Player(1,2,1);
    customer2 = new Player(1,3,2);
    customer3 = new Player(1,4,3);
    customer4 = new Player(1,5,4);
    order1 = new QPushButton ("Order 1");
    order2 = new QPushButton ("Order 2");
    order3 = new QPushButton ("Order 3");
    order4 = new QPushButton ("Order 4");
    customer5 = new Player(1,5,2);
    customer6 = new Player(1,6,3);
    order5 = new QPushButton ("Order 5");
    order6 = new QPushButton ("Order 6");
    customer7 = new Player(1,7,2);
    order7 = new QPushButton ("Order 7");
    board_setup();

    connect(order1, SIGNAL(clicked()), this,SLOT(customer_order1()));
    connect(order2, SIGNAL(clicked()), this,SLOT(customer_order2()));
    connect(order3, SIGNAL(clicked()), this,SLOT(customer_order3()));
    connect(order4, SIGNAL(clicked()), this,SLOT(customer_order4()));

    connect(mute, SIGNAL(clicked()),this,SLOT(stop_music()));
    connect(recipes, SIGNAL(clicked()),this,SLOT(goToMenu()));
    connect(backToGame, SIGNAL(clicked()),this,SLOT(goToSecondPage()));

    draw_walls();

    title_space->addWidget(text1);
    title_space->addWidget(health_text);
    title_space->addWidget(homeScreen);
    title_space->addWidget(mute);
    title_space->addWidget(recipes);

   /* for(int i = 0; i<10;i++){
            QLabel* testing = new QLabel("      ");
            play_space->addWidget(testing,i, 20);
    }
    for(int i = 0; i<10;i++){
            QLabel* testing = new QLabel("      ");
            play_space->addWidget(testing,20, i);
    }*/

    // places customers
    play_space->addWidget(customer1,customer1->get_pos_y(),customer1->get_pos_x());
    play_space->addWidget(order1, customer1->get_pos_y(),customer1->get_pos_x()+1);
    play_space->addWidget(customer2,customer2->get_pos_y(),customer2->get_pos_x());
    play_space->addWidget(order2, customer2->get_pos_y(),customer2->get_pos_x()+1);
    play_space->addWidget(customer3,customer3->get_pos_y(),customer3->get_pos_x());
    play_space->addWidget(order3, customer3->get_pos_y(),customer3->get_pos_x()+1);
    play_space->addWidget(customer4,customer4->get_pos_y(),customer4->get_pos_x());
    play_space->addWidget(order4, customer4->get_pos_y(),customer4->get_pos_x()+1);

    // places player
    play_space->addWidget(main_character, main_character->get_pos_y(),main_character->get_pos_x());

    // places breads
    play_space->addWidget(breadBin1,breadBin1->get_bin_pos_y(),breadBin1->get_bin_pos_x());
    play_space->addWidget(bread1,breadBin1->get_bin_pos_y(),breadBin1->get_bin_pos_x());
    play_space->addWidget(breadBin2,breadBin2->get_bin_pos_y(),breadBin2->get_bin_pos_x());
    play_space->addWidget(bread2,breadBin2->get_bin_pos_y(),breadBin2->get_bin_pos_x());
    play_space->addWidget(breadBin3,breadBin3->get_bin_pos_y(),breadBin3->get_bin_pos_x());
    play_space->addWidget(bread3,breadBin3->get_bin_pos_y(),breadBin3->get_bin_pos_x());

    // places cheeses
    play_space->addWidget(cheeseBin1,cheeseBin1->get_bin_pos_y(),cheeseBin1->get_bin_pos_x());
    play_space->addWidget(cheese1,cheeseBin1->get_bin_pos_y(),cheeseBin1->get_bin_pos_x());
    play_space->addWidget(cheeseBin2,cheeseBin2->get_bin_pos_y(),cheeseBin2->get_bin_pos_x());
    play_space->addWidget(cheese2,cheeseBin2->get_bin_pos_y(),cheeseBin2->get_bin_pos_x());
    play_space->addWidget(cheeseBin3,cheeseBin3->get_bin_pos_y(),cheeseBin3->get_bin_pos_x());
    play_space->addWidget(cheese3,cheeseBin3->get_bin_pos_y(),cheeseBin3->get_bin_pos_x());

    // places protein
    play_space->addWidget(meatBin1,meatBin1->get_bin_pos_y(),meatBin1->get_bin_pos_x());
    play_space->addWidget(meat1,meatBin1->get_bin_pos_y(),meatBin1->get_bin_pos_x());
    play_space->addWidget(meatBin2,meatBin2->get_bin_pos_y(),meatBin2->get_bin_pos_x());
    play_space->addWidget(meat2,meatBin2->get_bin_pos_y(),meatBin2->get_bin_pos_x());
    play_space->addWidget(meatBin3,meatBin3->get_bin_pos_y(),meatBin3->get_bin_pos_x());
    play_space->addWidget(meat3,meatBin3->get_bin_pos_y(),meatBin3->get_bin_pos_x());

    // places veggies
    play_space->addWidget(veggieBin1,veggieBin1->get_bin_pos_y(),veggieBin1->get_bin_pos_x());
    play_space->addWidget(veggies1,veggieBin1->get_bin_pos_y(),veggieBin1->get_bin_pos_x());
    play_space->addWidget(veggieBin2,veggieBin2->get_bin_pos_y(),veggieBin2->get_bin_pos_x());
    play_space->addWidget(veggies2,veggieBin2->get_bin_pos_y(),veggieBin2->get_bin_pos_x());
    play_space->addWidget(veggieBin3,veggieBin3->get_bin_pos_y(),veggieBin3->get_bin_pos_x());
    play_space->addWidget(veggies3,veggieBin3->get_bin_pos_y(),veggieBin3->get_bin_pos_x());

    // places trash can
    play_space->addWidget(trash,trash->get_bin_pos_y(),trash->get_bin_pos_x());

    secondPage = new QWidget;
    fullwindow = new QVBoxLayout(secondPage);
    fullwindow->addLayout(title_space);
    fullwindow->addLayout(play_space);

    stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(secondPage);

    // widgets that show when you win
    QLabel* win = new QLabel;
    QPixmap winPix(":/winscreen.png");
    winPix = winPix.scaled(850, 675, Qt::KeepAspectRatio, Qt::FastTransformation);
    win->setPixmap(winPix);
    QVBoxLayout *winLayout = new QVBoxLayout(win);
    QSpacerItem* space = new QSpacerItem(100, 600, QSizePolicy::Maximum, QSizePolicy::Maximum);
    winLayout->addItem(space);
    winLayout->addWidget(backToHome1, 0, Qt::AlignRight);

    QLabel* lose = new QLabel;
    QPixmap losePix(":/losescreen.png");
    losePix = losePix.scaled(850, 675, Qt::KeepAspectRatio, Qt::FastTransformation);
    lose->setPixmap(losePix);
    QVBoxLayout *loseLayout = new QVBoxLayout(lose);
    QSpacerItem* space2 = new QSpacerItem(100, 600, QSizePolicy::Maximum, QSizePolicy::Maximum);
    loseLayout->addItem(space2);
    loseLayout->addWidget(backToHome2, 0, Qt::AlignRight);

    stackedWidget->addWidget(win);
    stackedWidget->addWidget(lose);

    // widget that shows when you want to see sandwich recipes
    // still need pixil pic
    menuPage = new QWidget;
    menuPage->setStyleSheet("background-image: url(:/background.png)");
    menuLayout = new QVBoxLayout(menuPage);
    stackedWidget->addWidget(menuPage);
    QLabel* menuText = new QLabel( "RECIPES");
    menuText->setStyleSheet("QLabel { color : black }");
    menuLayout->addWidget(menuText);
    menuLayout->addWidget(backToGame);

    QVBoxLayout* centrallayout = new QVBoxLayout;
    centrallayout->addWidget(stackedWidget);
    setLayout(centrallayout);
}

void SecondWindow::board_setup(){
    if(challenge_number >= 1){
        if (customer6->check_presence()){
            customer6->remove_event();
            order6->hide();
        } if (customer5->check_presence()){
            customer5->remove_event();
            order5->hide();
        } if (customer7->check_presence()){
            customer7->remove_event();
            order7->hide();
        }
    } if(challenge_number >= 2){
        customer5 = new Player(1,5,2);
        customer6 = new Player(1,6,3);
        order5 = new QPushButton ("Order 5");
        order6 = new QPushButton ("Order 6");
        connect(order5, SIGNAL(clicked()), this,SLOT(customer_order5()));
        connect(order6, SIGNAL(clicked()), this,SLOT(customer_order6()));
        if (customer7->check_presence()){
            customer7->remove_event();
            order7->hide();
        }
    } if (challenge_number >=3 ){
        customer7 = new Player(1,7,2);
        order7 = new QPushButton ("Order 7");
        connect(order7, SIGNAL(clicked()), this,SLOT(customer_order7()));
    } if (challenge_number == 1){
       customer1->set_basic_sandwich();
       //std::cout<<"hi"<<endl;
       customer2->set_basic_sandwich();
       customer3->set_basic_sandwich();
       customer4->set_basic_sandwich();
   } else if(challenge_number == 2){
       customer1->set_basic_sandwich();
       customer2->set_intermediate_sandwich();
       customer3->set_expert_sandwich();
       customer4->set_intermediate_sandwich();
       customer5->set_basic_sandwich();
       customer6->set_intermediate_sandwich();
   } else if(challenge_number == 3){
       customer1->set_expert_sandwich();
       customer2->set_intermediate_sandwich();
       customer3->set_basic_sandwich();
       customer4->set_expert_sandwich();
       customer5->set_intermediate_sandwich();
       customer6->set_intermediate_sandwich();
       customer7->set_expert_sandwich();
   } if(challenge_number>=2){
       play_space->addWidget(customer5,customer5->get_pos_y(),customer5->get_pos_x());
       play_space->addWidget(order5, customer5->get_pos_y(),customer5->get_pos_x()+1);
       play_space->addWidget(customer6,customer6->get_pos_y(),customer6->get_pos_x());
       play_space->addWidget(order6, customer6->get_pos_y(),customer6->get_pos_x()+1);
   } if (challenge_number>=3){
       play_space->addWidget(customer7,customer7->get_pos_y(),customer7->get_pos_x());
       play_space->addWidget(order7, customer7->get_pos_y(),customer7->get_pos_x()+1);
   }
}

void SecondWindow::stop_music(){
    if(music_mute%2 == 0){
        music->setMedia(QUrl("qrc:/easy music.mp3"));
        music->play();
    }
    else {
        music->pause();
    }
    music_mute++;
}

void SecondWindow::customer_order1() {
    QString  a = *customer1->print_sandwich();
    text1->setText(" My order is: " + a);
    return;
}

void SecondWindow::customer_order2() {
    QString  a = *customer2->print_sandwich();
    text1->setText(" My order is: " + a);
    return;
}

void SecondWindow::customer_order3() {
    QString  a = *customer3->print_sandwich();
    text1->setText(" My order is: " + a);
    return;
}
void SecondWindow::customer_order4() {
    QString  a = *customer4->print_sandwich();
    text1->setText(" My order is: " + a);
    return;
}

void SecondWindow::customer_order5() {
    QString  a = *customer5->print_sandwich();
    text1->setText(" My order is: " + a);
    return;
}

void SecondWindow::customer_order6() {
    QString  a = *customer6->print_sandwich();
    text1->setText(" My order is: " + a);
    return;
}

void SecondWindow::customer_order7() {
    QString  a = *customer7->print_sandwich();
    text1->setText(" My order is: " + a);
    return;
}

void SecondWindow::draw_walls() {
    for (int i= 0; i<8; i++) {
        Wall* a= new Wall;
        play_space->addWidget(a,i,0);
    } for (int i= 0; i<8; i++) {
        Wall* a= new Wall;
        play_space->addWidget(a,i,16);
    } for (int i= 0; i<16; i++) {
        Wall* a= new Wall;
        play_space->addWidget(a,0,i);
    } for (int i= 0; i<16; i++) {
        Wall* a= new Wall;
        play_space->addWidget(a,8,i);
    }
}

void SecondWindow::decrease_health(){
    health = health - 1;
}

void SecondWindow::set_challenge_rating_w2(int a){
    challenge_number = a;
//    std::cout<<a<<std::endl;
}

void SecondWindow::goToSecondPage() {
    stackedWidget->setCurrentIndex(0);
}

void SecondWindow::goToLose() {
    stackedWidget->setCurrentIndex(2);
}

void SecondWindow::goToWin() {
    stackedWidget->setCurrentIndex(1);
}

void SecondWindow::goToMenu() {
    stackedWidget->setCurrentIndex(3);
}

void SecondWindow::keyPressEvent(QKeyEvent *event) {
    // to move the player
    if (event->key() == Qt::Key_A || event->key() == Qt::Key_Left) {
        if (main_character->get_pos_x() > 3) {
            main_character->move_left();
            play_space->addWidget(main_character, main_character->get_pos_y(),main_character->get_pos_x());
        }
    } else if(event->key() == Qt::Key_D||event->key() == Qt::Key_Right) {
        if (main_character->get_pos_x() < 16) {
            main_character->move_right();
            play_space->addWidget(main_character, main_character->get_pos_y(),main_character->get_pos_x());
        }
    } else if(event->key() == Qt::Key_W||event->key() == Qt::Key_Up) {
        if (main_character->get_pos_y() > 0) {
            main_character->move_up();
            play_space->addWidget(main_character, main_character->get_pos_y(),main_character->get_pos_x());
        }
    } else if(event->key() == Qt::Key_S||event->key() == Qt::Key_Down) {
        if (main_character->get_pos_y() < 8) {
            main_character->move_down();
            play_space->addWidget(main_character, main_character->get_pos_y(),main_character->get_pos_x());
        }
    } if (event->key() == Qt::Key_Space){
        if (main_character->get_pos_x() == cheeseBin1->get_bin_pos_x()&&main_character->get_pos_y() == cheeseBin1->get_bin_pos_y()) {
            Food* a = new Cheese("American Cheese");
            main_character->add_food(a);
        } if (main_character->get_pos_x() == cheeseBin2->get_bin_pos_x()&&main_character->get_pos_y() == cheeseBin2->get_bin_pos_y()) {
            Food* a = new Cheese("Swiss Cheese");
            main_character->add_food(a);
        } if (main_character->get_pos_x() == cheeseBin3->get_bin_pos_x()&&main_character->get_pos_y() == cheeseBin3->get_bin_pos_y()) {
            Food* a = new Cheese("Vegan Cheese");
            main_character->add_food(a);
        } if (main_character->get_pos_x() == breadBin1->get_bin_pos_x() && main_character->get_pos_y() == breadBin1->get_bin_pos_y()) {
            Food* a = new Bread("White Bread");
            main_character->add_food(a);
        } if (main_character->get_pos_x() == breadBin2->get_bin_pos_x() && main_character->get_pos_y() == breadBin2->get_bin_pos_y()) {
            Food* a = new Bread("Whole Wheat Bread");
            main_character->add_food(a);
        } if (main_character->get_pos_x() == breadBin3->get_bin_pos_x() && main_character->get_pos_y() == breadBin3->get_bin_pos_y()) {
            Food* a = new Bread("Prezel Bun");
            main_character->add_food(a);
        } if (main_character->get_pos_x() == meatBin1->get_bin_pos_x() && main_character->get_pos_y() == meatBin1->get_bin_pos_y()) {
            Food* a = new Meat("Turkey Meat");
            main_character->add_food(a);
        } if (main_character->get_pos_x() == meatBin2->get_bin_pos_x() && main_character->get_pos_y() == meatBin2->get_bin_pos_y()) {
            Food* a = new Meat("Steak");
            main_character->add_food(a);
        } if(main_character->get_pos_x() == meatBin3->get_bin_pos_x() && main_character->get_pos_y() == meatBin3->get_bin_pos_y()) {
            Food* a = new Meat("Impossible Meat");
            main_character->add_food(a);
        } if (main_character->get_pos_x() == veggieBin1->get_bin_pos_x() && main_character->get_pos_y() == veggieBin1->get_bin_pos_y()) {
            Food* a = new Veggies("Lettuce");
            main_character->add_food(a);
        } if (main_character->get_pos_x() == veggieBin2->get_bin_pos_x() && main_character->get_pos_y() == veggieBin2->get_bin_pos_y()) {
            Food* a = new Veggies("Peppers");
            main_character->add_food(a);
        } if (main_character->get_pos_x() == veggieBin3->get_bin_pos_x() && main_character->get_pos_y() == veggieBin3->get_bin_pos_y()) {
            Food* a = new Veggies("Spinach");
            main_character->add_food(a);
        }
    }
    // to clear the sandwich when player is touching the trash can
    if (main_character->get_pos_x() == trash->get_bin_pos_x() && main_character->get_pos_y()==trash->get_bin_pos_y()){
        main_character->delete_sandwich();
    }
    // to serve sandwiches
    if(event->key() == Qt::Key_G) {
        if ( main_character->get_pos_x()-2 == customer1->get_pos_x() && main_character->get_pos_y()==customer1->get_pos_y()&& customer1->check_presence()) {
            main_character->print_sandwich();
            if (main_character->check_order(customer1)){
               people_served++;
               main_character->delete_sandwich();
               text1->setText("Thanks!!");
               customer1->remove_event();
               order1->hide();
            } else {
                main_character->delete_sandwich();
                decrease_health();
                text1->setText(" Oh... that isn't what I asked for");
                health_text->setText("      Health: " + QString::number(health));
            }
        } else if( main_character->get_pos_x()-2 == customer2->get_pos_x() && main_character->get_pos_y()==customer2->get_pos_y()&& customer2->check_presence()) {
            main_character->print_sandwich();
            if (main_character->check_order(customer2)) {
                people_served++;
                main_character->delete_sandwich();
                text1->setText(" Thanks!!");
                customer2->remove_event();
                order2->hide();
            } else {
                main_character->delete_sandwich();
                decrease_health();
                text1->setText(" Oh... that isn't what I asked for");
                health_text->setText( "      Health: " + QString::number(health));
            }
        } else if( main_character->get_pos_x()-2 == customer3->get_pos_x() &&main_character->get_pos_y()==customer3->get_pos_y()&& customer3->check_presence()){
            main_character->print_sandwich();
            if (main_character->check_order(customer3)) {
                people_served++;
                main_character->delete_sandwich();
                customer3->remove_event();
                order3->hide();
                text1->setText(" Perfect! Thank you!");
            } else {
                main_character->delete_sandwich();
                decrease_health();
                health_text->setText("      Health: " + QString::number(health));
                text1->setText(" Um, No, Try again");
            }
        } else if( main_character->get_pos_x()-2 == customer4->get_pos_x() &&main_character->get_pos_y()==customer4->get_pos_y()&& customer4->check_presence()) {
            main_character->print_sandwich();
            if (main_character->check_order(customer4)) {
                people_served++;
                main_character->delete_sandwich();
                customer4->remove_event();
                order4->hide();
                text1->setText(" Yum!!! Thanks!");
            } else {
                main_character->delete_sandwich();
                decrease_health();
                health_text->setText("      Health: " + QString::number(health));
                text1->setText(" Oh... that isn't what I asked for");
            }
        } else if( main_character->get_pos_x()-2 == customer5->get_pos_x() &&main_character->get_pos_y()==customer5->get_pos_y()&& customer5->check_presence()) {
            main_character->print_sandwich();
            if (main_character->check_order(customer5)) {
                people_served++;
                main_character->delete_sandwich();
                customer5->remove_event();
                order5->hide();
                text1->setText(" Wow! Looks Great!");
            } else {
                main_character->delete_sandwich();
                decrease_health();
                health_text->setText("      Health: " + QString::number(health));
                text1->setText(" Hmm you aren't very good at this, hm?");
            }
        } else if( main_character->get_pos_x()-2 == customer6->get_pos_x() &&main_character->get_pos_y()==customer6->get_pos_y()&& customer6->check_presence()) {
            main_character->print_sandwich();
            if (main_character->check_order(customer6)) {
                people_served++;
                main_character->delete_sandwich();
                customer6->remove_event();
                order6->hide();
                text1->setText(" Perfect! Thanks!");
            } else {
                main_character->delete_sandwich();
                decrease_health();
                health_text->setText("      Health: " + QString::number(health));
                text1->setText(" Oh... that isn't what I asked for");
            }
        } else if( main_character->get_pos_x()-2 == customer7->get_pos_x() &&main_character->get_pos_y()==customer7->get_pos_y()&& customer7->check_presence()) {
                main_character->print_sandwich();
                if (main_character->check_order(customer7)) {
                    people_served++;
                    main_character->delete_sandwich();
                    customer7->remove_event();
                    order7->hide();
                    text1->setText(" Yum! Thanks!");
                } else {
                    main_character->delete_sandwich();
                    decrease_health();
                    health_text->setText("      Health: " + QString::number(health));
                    text1->setText(" No,no, that isn't right");
                }
        } if (challenge_number == 1 && people_served == 4) {
            goToWin(); // maybe only "you've been promoted"?
        } else if (challenge_number== 2 && people_served == 6) {
            goToWin(); // maybe only "you've been promoted"?
        } else if (challenge_number== 3 && people_served == 7) {
            goToWin(); // "you win"
        } if(health == 0){
            goToLose();
        }
    }
    return;
}

void SecondWindow::setPartner(QWidget* partner) {
    if (partner == 0)
        return;
    if (mPartner != partner) {
        if (mPartner != 0) {
            disconnect(homeScreen, SIGNAL(clicked()), this, SLOT(hide()));
            disconnect(homeScreen, SIGNAL(clicked()), mPartner, SLOT(showMaximized()));
//            disconnect(backToHome, SIGNAL(clicked()), this, SLOT(hide()));
//            disconnect(backToHome, SIGNAL(clicked()), mPartner, SLOT(showMaximized()));
        }
        mPartner = partner;
        connect(homeScreen, SIGNAL(clicked()), this, SLOT(hide()));
        connect(homeScreen, SIGNAL(clicked()), mPartner, SLOT(showMaximized()));
//        connect(backToHome, SIGNAL(clicked()), this, SLOT(hide()));
//        connect(backToHome, SIGNAL(clicked()), mPartner, SLOT(showMaximized()));
    }
}

SecondWindow::~SecondWindow(){
    delete main_character;
    delete customer1;
    delete customer2;
    delete customer3;
    delete customer4;
}
