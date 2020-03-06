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
    music->setMedia(QUrl("qrc:/easy music.mp3"));
    stop_music();

    // button to mute music
    mute = new QPushButton;
    QPixmap mutePix(":/music.png");
    mutePix = mutePix.scaled(102, 60, Qt::KeepAspectRatio, Qt::FastTransformation);
    QIcon muteIcon(mutePix);
    mute->setIcon(muteIcon);
    mute->setIconSize(mutePix.rect().size());
    mute->setFixedSize(mutePix.rect().size());

    // button to see sandwich recipes
    toRecipes = new QPushButton;
    QPixmap recipesPix(":/recipes.png");
    recipesPix = recipesPix.scaled(125, 60, Qt::KeepAspectRatio, Qt::FastTransformation);
    QIcon recipesIcon(recipesPix);
    toRecipes->setIcon(recipesIcon);
    toRecipes->setIconSize(recipesPix.rect().size());
    toRecipes->setFixedSize(recipesPix.rect().size());

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

    title_space = new QHBoxLayout();
    play_space = new QGridLayout();

   /* QTimer* timer = new QTimer(this);
       connect(timer, SIGNAL(timeout()), this, SLOT(update()));
       timer->start(1000);*/

//    QLabel* bread2 = new QLabel("Whole\nWheat\nBread");

    QLabel* cheese1 = new QLabel("American\nCheese");
    QLabel* cheese2 = new QLabel("Swiss\nCheese");
    QLabel* cheese3 = new QLabel("Vegan\nCheese");

    text1 = new QLabel(" Welcome to Heck's Kitchen!");
    text1->setAlignment(Qt::AlignCenter);
    text1->setFixedWidth(225);
    text1->setStyleSheet("QLabel { color : black }");
    health_text = new QLabel("      Health: "+ QString::number(health) );
    health_text->setStyleSheet("QLabel { color : black }");
    player_health = new Health();
    main_character = new Player();

    breadBin1 = new Bread_Bin(6,2, "White Bread");
    breadBin2 = new Bread_Bin(7,2, "Whole Wheat Bread");
    breadBin3 = new Bread_Bin(8,2, "Pretzel Bun");

    cheeseBin1 = new Cheese_Bin(10,3, "American Cheese");
    cheeseBin2 = new Cheese_Bin(10,4, "Swiss Cheese");
    cheeseBin3 = new Cheese_Bin(10,5, "Vegan Cheese");

    meatBin1 = new Meat_Bin(10,6, "Turkey Meat");
    meatBin2 = new Meat_Bin(10,7, "Steak");
    meatBin3 = new Meat_Bin(10,8, "Immpossible Meat");

    veggieBin1 = new Veggie_Bin(5,7, "Lettuce");
    veggieBin2 = new Veggie_Bin(6,7, "Peppers");
    veggieBin3 = new Veggie_Bin(7,7, "Spinach");

    trash = new Bin(4, 2);
    trash2 = new Bin(8, 9);

    connect(mute, SIGNAL(clicked()),this,SLOT(stop_music()));
    connect(backToGame, SIGNAL(clicked()),this,SLOT(goToGamePage()));

//    QSpacerItem* top = new QSpacerItem(700, 100, QSizePolicy::Maximum, QSizePolicy::Maximum);
//    title_space->addItem(top, 1, 1, 2, 10, Qt::AlignCenter);
    title_space->addWidget(text1);
    title_space->setSpacing(15);
    title_space->addWidget(health_text);
    title_space->addWidget(player_health);
    title_space->addWidget(homeScreen);
    title_space->addWidget(mute);
    title_space->addWidget(toRecipes);

    QSpacerItem* one = new QSpacerItem(200, 200, QSizePolicy::Fixed, QSizePolicy::Fixed);
    play_space->addItem(one, 1, 1, 1, 13);
    QSpacerItem* two = new QSpacerItem(50, 50, QSizePolicy::Fixed, QSizePolicy::Fixed);
    play_space->addItem(two, 2, 1, 1, 13);
    QSpacerItem* three = new QSpacerItem(50, 50, QSizePolicy::Fixed, QSizePolicy::Fixed);
    play_space->addItem(three, 3, 1, 1, 13);
    QSpacerItem* four = new QSpacerItem(50, 50, QSizePolicy::Fixed, QSizePolicy::Fixed);
    play_space->addItem(four, 4, 1, 1, 13);
    QSpacerItem* five = new QSpacerItem(50, 50, QSizePolicy::Fixed, QSizePolicy::Fixed);
    play_space->addItem(five, 5, 1, 1, 13);
    QSpacerItem* six = new QSpacerItem(50, 50, QSizePolicy::Fixed, QSizePolicy::Fixed);
    play_space->addItem(six, 6, 1, 1, 13);
    QSpacerItem* seven = new QSpacerItem(50, 50, QSizePolicy::Fixed, QSizePolicy::Fixed);
    play_space->addItem(seven, 7, 1, 1, 13);
    QSpacerItem* eight = new QSpacerItem(50, 50, QSizePolicy::Fixed, QSizePolicy::Fixed);
    play_space->addItem(eight, 8, 1, 1, 13);
    QSpacerItem* nine = new QSpacerItem(200, 200, QSizePolicy::Fixed, QSizePolicy::Fixed);
    play_space->addItem(nine, 9, 1, 1, 13);

    // places player
    play_space->addWidget(main_character, main_character->get_pos_y(),main_character->get_pos_x());

    // places breads
    play_space->addWidget(breadBin1,breadBin1->get_bin_pos_y(),breadBin1->get_bin_pos_x());
    play_space->addWidget(breadBin2,breadBin2->get_bin_pos_y(),breadBin2->get_bin_pos_x());
    play_space->addWidget(breadBin3,breadBin3->get_bin_pos_y(),breadBin3->get_bin_pos_x());

    // places cheeses
    play_space->addWidget(cheeseBin1,cheeseBin1->get_bin_pos_y(),cheeseBin1->get_bin_pos_x());
    play_space->addWidget(cheese1,cheeseBin1->get_bin_pos_y(),cheeseBin1->get_bin_pos_x());
    play_space->addWidget(cheeseBin2,cheeseBin2->get_bin_pos_y(),cheeseBin2->get_bin_pos_x());
    play_space->addWidget(cheese2,cheeseBin2->get_bin_pos_y(),cheeseBin2->get_bin_pos_x());
    play_space->addWidget(cheeseBin3,cheeseBin3->get_bin_pos_y(),cheeseBin3->get_bin_pos_x());
    play_space->addWidget(cheese3,cheeseBin3->get_bin_pos_y(),cheeseBin3->get_bin_pos_x());

    // places protein
    play_space->addWidget(meatBin1,meatBin1->get_bin_pos_y(),meatBin1->get_bin_pos_x());
    play_space->addWidget(meatBin2,meatBin2->get_bin_pos_y(),meatBin2->get_bin_pos_x());
    play_space->addWidget(meatBin3,meatBin3->get_bin_pos_y(),meatBin3->get_bin_pos_x());

    // places veggies
    play_space->addWidget(veggieBin1,veggieBin1->get_bin_pos_y(),veggieBin1->get_bin_pos_x());
    play_space->addWidget(veggieBin2,veggieBin2->get_bin_pos_y(),veggieBin2->get_bin_pos_x());
    play_space->addWidget(veggieBin3,veggieBin3->get_bin_pos_y(),veggieBin3->get_bin_pos_x());

    // places trash can
    play_space->addWidget(trash,trash->get_bin_pos_y(),trash->get_bin_pos_x());
    play_space->addWidget(trash2,trash2->get_bin_pos_y(),trash2->get_bin_pos_x());

    secondPage = new QWidget;
    fullwindow = new QVBoxLayout(secondPage);
    fullwindow->addLayout(title_space);
    fullwindow->addLayout(play_space);

    stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(secondPage);

    // 'Back' buttons on the win and lose pages
    backToHome1 = new QPushButton;
    QPixmap backPix(":/back.png");
    backPix = backPix.scaled(650, 500, Qt::KeepAspectRatio, Qt::FastTransformation);
    backToHome1->setIcon(backPix);
    backToHome1->setIconSize(backPix.rect().size());
    backToHome1->setFixedSize(backPix.rect().size());

    connect(backToHome1, SIGNAL(clicked()),this,SLOT(goToGamePage())); // RIGHT NOW, WHEN YOU WIN/LOSE YOU CAN ONLY EXIT TO THE GAME SCREEN, NOT THE HOME SCREEN

    backToHome2 = new QPushButton;
    backPix = backPix.scaled(650, 500, Qt::KeepAspectRatio, Qt::FastTransformation);
    backToHome2->setIcon(backPix);
    backToHome2->setIconSize(backPix.rect().size());
    backToHome2->setFixedSize(backPix.rect().size());

    connect(backToHome2, SIGNAL(clicked()),this,SLOT(goToGamePage())); // RIGHT NOW, WHEN YOU WIN/LOSE YOU CAN ONLY EXIT TO THE GAME SCREEN, NOT THE HOME SCREEN

    QLabel* win = new QLabel;
    QPixmap winPix(":/winscreen.png");
    winPix = winPix.scaled(850, 675, Qt::KeepAspectRatio, Qt::FastTransformation);
    win->setPixmap(winPix);
    QVBoxLayout *winLayout = new QVBoxLayout(win);
    QSpacerItem* space = new QSpacerItem(100, 600, QSizePolicy::Maximum, QSizePolicy::Maximum);
    winLayout->addItem(space);
    winLayout->addWidget(backToHome1, 0, Qt::AlignCenter);

    QLabel* lose = new QLabel;
    QPixmap losePix(":/losescreen.png");
    losePix = losePix.scaled(850, 675, Qt::KeepAspectRatio, Qt::FastTransformation);
    lose->setPixmap(losePix);
    QVBoxLayout *loseLayout = new QVBoxLayout(lose);
    QSpacerItem* space2 = new QSpacerItem(100, 600, QSizePolicy::Maximum, QSizePolicy::Maximum);
    loseLayout->addItem(space2);
    loseLayout->addWidget(backToHome2, 0, Qt::AlignCenter);

    stackedWidget->addWidget(win);
    stackedWidget->addWidget(lose);

    QVBoxLayout *centrallayout = new QVBoxLayout;
    centrallayout->addWidget(stackedWidget);
    setLayout(centrallayout);

    begin_game();
}

void SecondWindow::begin_game(){
    text1->setText("Welcome to Heck's Kitchen");
    people_served = 0;
    health_text->setText("      Health: " + QString::number(health));
    puddle1 = new Puddle(1,1);
    puddle2 = new Puddle(0,0);
    health = 10;
    player_health->reset_health();

    customer1 = new Player(1,3,1);
    customer2 = new Player(1,4,2);
    customer3 = new Player(1,5,3);
    customer4 = new Player(1,6,4);
    customer5 = new Player(1,7,2);
    customer6 = new Player(1,8,3);
    customer7 = new Player(1,9,2);
    order1 = new QPushButton ("Order 1");
    order2 = new QPushButton ("Order 2");
    order3 = new QPushButton ("Order 3");
    order4 = new QPushButton ("Order 4");
    order5 = new QPushButton ("Order 5");
    order6 = new QPushButton ("Order 6");
    order7 = new QPushButton ("Order 7");
    customer1->create_event();

    customer_setup();
}

void SecondWindow::customer_setup(){
    if(challenge_number >= 1){
        customer1 = new Player(1,3,1);
        customer2 = new Player(1,4,2);
        customer3 = new Player(1,5,3);
        customer4 = new Player(1,6,4);
        order1 = new QPushButton ("Order 1");
        order2 = new QPushButton ("Order 2");
        order3 = new QPushButton ("Order 3");
        order4 = new QPushButton ("Order 4");
        play_space->addWidget(customer1,customer1->get_pos_y(),customer1->get_pos_x());
        play_space->addWidget(order1, customer1->get_pos_y(),customer1->get_pos_x()+1);
        play_space->addWidget(customer2,customer2->get_pos_y(),customer2->get_pos_x());
        play_space->addWidget(order2, customer2->get_pos_y(),customer2->get_pos_x()+1);
        play_space->addWidget(customer3,customer3->get_pos_y(),customer3->get_pos_x());
        play_space->addWidget(order3, customer3->get_pos_y(),customer3->get_pos_x()+1);
        play_space->addWidget(customer4,customer4->get_pos_y(),customer4->get_pos_x());
        play_space->addWidget(order4, customer4->get_pos_y(),customer4->get_pos_x()+1);
        connect(order1, SIGNAL(clicked()), this,SLOT(customer_order1()));
        connect(order2, SIGNAL(clicked()), this,SLOT(customer_order2()));
        connect(order3, SIGNAL(clicked()), this,SLOT(customer_order3()));
        connect(order4, SIGNAL(clicked()), this,SLOT(customer_order4()));
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
        customer5 = new Player(1,7,2);
        customer6 = new Player(1,8,3);
        order5 = new QPushButton ("Order 5");
        order6 = new QPushButton ("Order 6");
        puddle1 = new Puddle(1,1);
        puddle1 = puddle1->set_random_location();
        play_space->addWidget(puddle1,puddle1->get_bin_pos_y(),puddle1->get_bin_pos_x());
        play_space->addWidget(customer5,customer5->get_pos_y(),customer5->get_pos_x());
        play_space->addWidget(order5, customer5->get_pos_y(),customer5->get_pos_x()+1);
        play_space->addWidget(customer6,customer6->get_pos_y(),customer6->get_pos_x());
        play_space->addWidget(order6, customer6->get_pos_y(),customer6->get_pos_x()+1);
        connect(order5, SIGNAL(clicked()), this,SLOT(customer_order5()));
        connect(order6, SIGNAL(clicked()), this,SLOT(customer_order6()));
        if (customer7->check_presence()){
            customer7->remove_event();
            order7->hide();
        }
    } if (challenge_number >=3 ) {
        customer7 = new Player(1,9,2);
        order7 = new QPushButton ("Order 7");
        play_space->addWidget(customer7,customer7->get_pos_y(),customer7->get_pos_x());
        play_space->addWidget(order7, customer7->get_pos_y(),customer7->get_pos_x()+1);
        connect(order7, SIGNAL(clicked()), this,SLOT(customer_order7()));
    } if (challenge_number == 1) {
        customer1->set_basic_sandwich();
        //std::cout<<"hi"<<endl;
        customer2->set_basic_sandwich();
        customer3->set_basic_sandwich();
        customer4->set_basic_sandwich();
    } else if(challenge_number == 2) {
        customer1->set_basic_sandwich();
        customer2->set_intermediate_sandwich();
        customer3->set_expert_sandwich();
        customer4->set_intermediate_sandwich();
        customer5->set_basic_sandwich();
        customer6->set_intermediate_sandwich();
    } else if(challenge_number == 3) {
        customer1->set_expert_sandwich();
        customer2->set_intermediate_sandwich();
        customer3->set_basic_sandwich();
        customer4->set_expert_sandwich();
        customer5->set_intermediate_sandwich();
        customer6->set_intermediate_sandwich();
        customer7->set_expert_sandwich();
    }
}

//    if(challenge_number >= 1){
//        play_space->addWidget(customer1,customer1->get_pos_y(),customer1->get_pos_x());
//        play_space->addWidget(order1, customer1->get_pos_y(),customer1->get_pos_x()+1);
//        play_space->addWidget(customer2,customer2->get_pos_y(),customer2->get_pos_x());
//        play_space->addWidget(order2, customer2->get_pos_y(),customer2->get_pos_x()+1);
//        play_space->addWidget(customer3,customer3->get_pos_y(),customer3->get_pos_x());
//        play_space->addWidget(order3, customer3->get_pos_y(),customer3->get_pos_x()+1);
//        play_space->addWidget(customer4,customer4->get_pos_y(),customer4->get_pos_x());
//        play_space->addWidget(order4, customer4->get_pos_y(),customer4->get_pos_x()+1);
//        connect(order1, SIGNAL(clicked()), this,SLOT(customer_order1()));
//        connect(order2, SIGNAL(clicked()), this,SLOT(customer_order2()));
//        connect(order3, SIGNAL(clicked()), this,SLOT(customer_order3()));
//        connect(order4, SIGNAL(clicked()), this,SLOT(customer_order4()));
//            if (customer6->check_presence()){
//                customer6->remove_event();
//                order6->hide();
//            } if (customer5->check_presence()){
//                customer5->remove_event();
//                order5->hide();
//            } if (customer7->check_presence()){
//                customer7->remove_event();
//                order7->hide();
//            }
//        } if(challenge_number >= 2){
//            customer5 = new Player(1,7,2);
//            customer6 = new Player(1,8,3);
//            order5 = new QPushButton ("Order 5");
//            order6 = new QPushButton ("Order 6");
//            play_space->addWidget(customer5,customer5->get_pos_y(),customer5->get_pos_x());
//            play_space->addWidget(order5, customer5->get_pos_y(),customer5->get_pos_x()+1);
//            play_space->addWidget(customer6,customer6->get_pos_y(),customer6->get_pos_x());
//            play_space->addWidget(order6, customer6->get_pos_y(),customer6->get_pos_x()+1);
//            connect(order5, SIGNAL(clicked()), this,SLOT(customer_order5()));
//            connect(order6, SIGNAL(clicked()), this,SLOT(customer_order6()));
//            if (customer7->check_presence()){
//                customer7->remove_event();
//                order7->hide();
//            }
//        } if (challenge_number >=3 ){
//            customer7 = new Player(1,9,2);
//            order7 = new QPushButton ("Order 7");
//            play_space->addWidget(customer7,customer7->get_pos_y(),customer7->get_pos_x());
//            play_space->addWidget(order7, customer7->get_pos_y(),customer7->get_pos_x()+1);
//            connect(order7, SIGNAL(clicked()), this,SLOT(customer_order7()));
//        } if (challenge_number == 1){
//           customer1->set_basic_sandwich();
//           //std::cout<<"hi"<<endl;
//           customer2->set_basic_sandwich();
//           customer3->set_basic_sandwich();
//           customer4->set_basic_sandwich();
//       } else if(challenge_number == 2){
//           customer1->set_basic_sandwich();
//           customer2->set_intermediate_sandwich();
//           customer3->set_expert_sandwich();
//           customer4->set_intermediate_sandwich();
//           customer5->set_basic_sandwich();
//           customer6->set_intermediate_sandwich();
//       } else if(challenge_number == 3){
//           customer1->set_expert_sandwich();
//           customer2->set_intermediate_sandwich();
//           customer3->set_basic_sandwich();
//           customer4->set_expert_sandwich();
//           customer5->set_intermediate_sandwich();
//           customer6->set_intermediate_sandwich();
//           customer7->set_expert_sandwich();
//       } /*if(challenge_number>=2){
////           play_space->addWidget(customer5,customer5->get_pos_y(),customer5->get_pos_x());
////           play_space->addWidget(order5, customer5->get_pos_y(),customer5->get_pos_x()+1);
////           play_space->addWidget(customer6,customer6->get_pos_y(),customer6->get_pos_x());
////           play_space->addWidget(order6, customer6->get_pos_y(),customer6->get_pos_x()+1);
//       }*/ /*if (challenge_number>=3){
//           play_space->addWidget(customer7,customer7->get_pos_y(),customer7->get_pos_x());
//           play_space->addWidget(order7, customer7->get_pos_y(),customer7->get_pos_x()+1);
//       }*/
//    }

void SecondWindow::reset_game() {
    delete_game();
    this->hide();
    begin_game();
}

void SecondWindow::delete_game() {
    customer1->remove_event();
    customer2->remove_event();
    customer3->remove_event();
    customer4->remove_event();
    customer5->remove_event();
    customer6->remove_event();
    customer7->remove_event();
    delete customer1;
    delete customer2;
    delete customer3;
    delete customer4;
    delete customer5;
    delete customer6;
    delete customer7;
    delete order1;
    delete order2;
    delete order3;
    delete order4;
    delete order5;
    delete order6;
    delete order7;
    delete puddle1;
}

void SecondWindow::stop_music(){
    if(music_mute%2 == 0){
        music->play();
    } else {
           music->pause();
    } music_mute++;
}

void SecondWindow::customer_order1() {
    QString  a = *customer1->get_sandwich_name();
    text1->setText(" My order is: " + a);
    return;
}

void SecondWindow::customer_order2() {
    QString  a = *customer2->get_sandwich_name();
    text1->setText(" My order is: " + a);
    return;
}

void SecondWindow::customer_order3() {
    QString  a = *customer3->get_sandwich_name();
    text1->setText(" My order is: " + a);
    return;
}
void SecondWindow::customer_order4() {
    QString  a = *customer4->get_sandwich_name();
    text1->setText(" My order is: " + a);
    return;
}

void SecondWindow::customer_order5() {
    QString  a = *customer5->get_sandwich_name();
    text1->setText(" My order is: " + a);
    return;
}

void SecondWindow::customer_order6() {
    QString  a = *customer6->get_sandwich_name();
    text1->setText(" My order is: " + a);
    return;
}

void SecondWindow::customer_order7() {
    QString  a = *customer7->get_sandwich_name();
    text1->setText(" My order is: " + a);
    return;
}

void SecondWindow::decrease_health(){
    health = health - 1;
}

void SecondWindow::set_challenge_rating_w2(int a){
    challenge_number = a;
//    std::cout<<a<<std::endl;
}

void SecondWindow::goToGamePage() {
    stackedWidget->setCurrentIndex(0);
}

void SecondWindow::goToLose() {
    stackedWidget->setCurrentIndex(2);
}

void SecondWindow::goToWin() {
    stackedWidget->setCurrentIndex(1);
}

//void SecondWindow::goToMenu() {
//    stackedWidget->setCurrentIndex(3);
//}

void SecondWindow::keyPressEvent(QKeyEvent *event) {
    // to move the player
    if (event->key() == Qt::Key_A || event->key() == Qt::Key_Left) {
        if (main_character->get_pos_x() > 3) {
            main_character->move_left();
            play_space->addWidget(main_character, main_character->get_pos_y(),main_character->get_pos_x());
        }
    } else if(event->key() == Qt::Key_D||event->key() == Qt::Key_Right) {
        if (main_character->get_pos_x() < 11) {
            main_character->move_right();
            play_space->addWidget(main_character, main_character->get_pos_y(),main_character->get_pos_x());
        }
    } else if(event->key() == Qt::Key_W||event->key() == Qt::Key_Up) {
        if (main_character->get_pos_y() > 2) {
            main_character->move_up();
            play_space->addWidget(main_character, main_character->get_pos_y(),main_character->get_pos_x());
        }
    } else if(event->key() == Qt::Key_S||event->key() == Qt::Key_Down) {
        if (main_character->get_pos_y() < 9) {
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
            Food* a = new Bread("Pretzel Bun");
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
    // to clear the sandwich when player is touching the trash can or slips on puddle
    if (main_character->get_pos_x() == trash->get_bin_pos_x() && main_character->get_pos_y()==trash->get_bin_pos_y()){
        main_character->delete_sandwich();
    } if (main_character->get_pos_x() == trash2->get_bin_pos_x() && main_character->get_pos_y()==trash2->get_bin_pos_y()){
        main_character->delete_sandwich();
    } if(main_character->get_pos_x() == puddle1->get_bin_pos_x() && main_character->get_pos_y()==puddle1->get_bin_pos_y()){
        main_character->delete_sandwich();
//        decrease_health();
    }
    // to serve sandwiches
    if(event->key() == Qt::Key_G) {
        if ( main_character->get_pos_x()-2 == customer1->get_pos_x() && main_character->get_pos_y()==customer1->get_pos_y()&& customer1->check_presence()) {
            main_character->get_sandwich_name();
            if (main_character->check_order(customer1)) {
                people_served++;
                main_character->delete_sandwich();
                text1->setText("Thanks!!");
                customer1->remove_event();
                order1->hide();
            } else {
                main_character->delete_sandwich();
                decrease_health();
                text1->setText(" Oh... that isn't what I asked for");
                player_health->change_health_bar();
                health_text->setText("      Health: " + QString::number(health));
            }
        } else if( main_character->get_pos_x()-2 == customer2->get_pos_x() && main_character->get_pos_y()==customer2->get_pos_y()&& customer2->check_presence()) {
            main_character->get_sandwich_name();
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
                player_health->change_health_bar();
                health_text->setText( "      Health: " + QString::number(health));
            }
        } else if( main_character->get_pos_x()-2 == customer3->get_pos_x() &&main_character->get_pos_y()==customer3->get_pos_y()&& customer3->check_presence()){
            main_character->get_sandwich_name();
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
                player_health->change_health_bar();
                text1->setText(" Um, No, Try again");
            }
        } else if( main_character->get_pos_x()-2 == customer4->get_pos_x() &&main_character->get_pos_y()==customer4->get_pos_y()&& customer4->check_presence()) {
            main_character->get_sandwich_name();
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
                player_health->change_health_bar();
                text1->setText(" Oh... that isn't what I asked for");
            }
        } else if( main_character->get_pos_x()-2 == customer5->get_pos_x() &&main_character->get_pos_y()==customer5->get_pos_y()&& customer5->check_presence()) {
            main_character->get_sandwich_name();
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
                player_health->change_health_bar();
                text1->setText(" Hmm you aren't very good at this, hm?");
            }
        } else if( main_character->get_pos_x()-2 == customer6->get_pos_x() &&main_character->get_pos_y()==customer6->get_pos_y()&& customer6->check_presence()) {
            main_character->get_sandwich_name();
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
                player_health->change_health_bar();
                text1->setText(" Oh... that isn't what I asked for");
            }
        } else if( main_character->get_pos_x()-2 == customer7->get_pos_x() &&main_character->get_pos_y()==customer7->get_pos_y()&& customer7->check_presence()) {
            main_character->get_sandwich_name();
            if (main_character->check_order(customer7)) {
                people_served++;
                main_character->delete_sandwich();
                customer7->remove_event();
                order7->hide();
                text1->setText(" Yum! Thanks!");
            } else {
                main_character->delete_sandwich();
                decrease_health();
                player_health->change_health_bar();
                health_text->setText("      Health: " + QString::number(health));
                text1->setText(" No,no, that isn't right");
            }
        } if (challenge_number == 1 && people_served == 4) {
            goToWin();
        } else if (challenge_number== 2 && people_served == 6) {
            goToWin();
        } else if (challenge_number== 3 && people_served == 7) {
            goToWin();
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
            disconnect(homeScreen, SIGNAL(clicked()), this, SLOT(reset_game()));
            disconnect(homeScreen, SIGNAL(clicked()), mPartner, SLOT(showMaximized()));
        }
        mPartner = partner;
        connect(homeScreen, SIGNAL(clicked()), this, SLOT(reset_game()));
        connect(homeScreen, SIGNAL(clicked()), mPartner, SLOT(showMaximized()));
    }
}

void SecondWindow::setPartner2(RecipeWindow *partner) {
    if (partner == 0)
        return;
    if (mPartner2 != partner) {
        if (mPartner2 != 0) {
            disconnect(toRecipes, SIGNAL(clicked()), this, SLOT(hide()));
            disconnect(toRecipes, SIGNAL(clicked()), mPartner2, SLOT(showMaximized()));
        }
        mPartner2 = partner;
        connect(toRecipes, SIGNAL(clicked()), this, SLOT(hide()));
        connect(toRecipes, SIGNAL(clicked()), mPartner2, SLOT(showMaximized()));
    }
}

SecondWindow::~SecondWindow() {}

RecipeWindow::RecipeWindow(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(875,700);
    QPixmap recipes1(":/recipes1.png");
    recipes1 = recipes1.scaled(this->size(), Qt::IgnoreAspectRatio);
    recipebkgnd.setBrush(QPalette::Background, recipes1);
    this->setPalette(recipebkgnd);

//    QWidget* recipePage = new QWidget();

    buttonLayout= new QGridLayout();

    recipeBack = new QPushButton;
    QPixmap recipeBackPix(":/recipeback.png");
    recipeBackPix = recipeBackPix.scaled(50, 50, Qt::KeepAspectRatio, Qt::FastTransformation);
    recipeBack->setIcon(recipeBackPix);
    recipeBack->setIconSize(recipeBackPix.rect().size());
    recipeBack->setFixedSize(recipeBackPix.rect().size());
    connect(recipeBack, SIGNAL(clicked()), this, SLOT(goBack()));

    recipeForward = new QPushButton;
    QPixmap recipeForwardPix(":/recipeforward.png");
    recipeForwardPix = recipeForwardPix.scaled(50, 50, Qt::KeepAspectRatio, Qt::FastTransformation);
    recipeForward->setIcon(recipeForwardPix);
    recipeForward->setIconSize(recipeForwardPix.rect().size());
    recipeForward->setFixedSize(recipeForwardPix.rect().size());
    connect(recipeForward, SIGNAL(clicked()), this, SLOT(goForward()));

    toSecondW = new QPushButton;
    QPixmap toSecondWPix(":/back.png");
    toSecondWPix = toSecondWPix.scaled(650, 500, Qt::KeepAspectRatio, Qt::FastTransformation);
    toSecondW->setIcon(toSecondWPix);
    toSecondW->setIconSize(toSecondWPix.rect().size());
    toSecondW->setFixedSize(toSecondWPix.rect().size());

    QSpacerItem* top = new QSpacerItem(300, 600, QSizePolicy::Maximum, QSizePolicy::Maximum);
    QSpacerItem* right = new QSpacerItem(10, 10, QSizePolicy::Maximum, QSizePolicy::Maximum);
    buttonLayout->addItem(top, 1, 1, 2, 4, Qt::AlignCenter);
    buttonLayout->addItem(right, 2, 1, 2, 1, Qt::AlignCenter);
    buttonLayout->addWidget(recipeBack, 3, 3, Qt::AlignRight);
    buttonLayout->addWidget(recipeForward, 3, 4, Qt::AlignLeft);
    buttonLayout->addWidget(toSecondW, 3, 1, Qt::AlignRight);
    recipeBack->hide();
    setLayout(buttonLayout);
}

void RecipeWindow::goForward(){
    if (recipeCounter == 4){
        recipeForward->hide();
        return;}
    else if (recipeCounter == 1){
        recipeBack->show();
        ++recipeCounter;
        QPixmap recipes2(":/recipes2.png");
        recipes2 = recipes2.scaled(this->size(), Qt::IgnoreAspectRatio);
        recipebkgnd.setBrush(QPalette::Background, recipes2);
        this->setPalette(recipebkgnd);
    }
    else if (recipeCounter == 2){
        ++recipeCounter;
        QPixmap recipes3(":/recipes3.png");
        recipes3 = recipes3.scaled(this->size(), Qt::IgnoreAspectRatio);
        recipebkgnd.setBrush(QPalette::Background, recipes3);
        this->setPalette(recipebkgnd);
    }
    else if (recipeCounter == 3){
        ++recipeCounter;
         recipeForward->hide();
        QPixmap recipes4(":/recipes4.png");
        recipes4 = recipes4.scaled(this->size(), Qt::IgnoreAspectRatio);
        recipebkgnd.setBrush(QPalette::Background, recipes4);
        this->setPalette(recipebkgnd);
    }
}

void RecipeWindow::goBack(){
    if (recipeCounter == 1){
        recipeBack->hide();
        return;}
    else if (recipeCounter == 2){
        recipeBack->hide();
        --recipeCounter;
        QPixmap recipes1(":/recipes1.png");
        recipes1 = recipes1.scaled(this->size(), Qt::IgnoreAspectRatio);
        recipebkgnd.setBrush(QPalette::Background, recipes1);
        this->setPalette(recipebkgnd);
    }
    else if (recipeCounter == 3){
        --recipeCounter;
        QPixmap recipes2(":/recipes2.png");
        recipes2 = recipes2.scaled(this->size(), Qt::IgnoreAspectRatio);
        recipebkgnd.setBrush(QPalette::Background, recipes2);
        this->setPalette(recipebkgnd);
    }
    else if (recipeCounter == 4){
        recipeForward->show();
        --recipeCounter;
        QPixmap recipes3(":/recipes3.png");
        recipes3 = recipes3.scaled(this->size(), Qt::IgnoreAspectRatio);
        recipebkgnd.setBrush(QPalette::Background, recipes3);
        this->setPalette(recipebkgnd);
    }
}

void RecipeWindow::setPartner2(SecondWindow* partner) {
    if (partner == 0)
        return;
    if (mPartner2 != partner) {
        if(mPartner2 != 0) {
            disconnect(toSecondW, SIGNAL(clicked()), this, SLOT(hide()));
            disconnect(toSecondW, SIGNAL(clicked()), mPartner2, SLOT(showMaximized()));
        }
        mPartner2 = partner;
        connect(toSecondW, SIGNAL(clicked()), this, SLOT(hide()));
        connect(toSecondW, SIGNAL(clicked()), mPartner2, SLOT(showMaximized()));
        }
}

RecipeWindow::~ RecipeWindow(){}
