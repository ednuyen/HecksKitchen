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

    // music does not play automatically, press Toggle Music! to turn on/off music
    music = new QMediaPlayer(this);
    mute = new QPushButton("Toggle Music!");
    QPushButton* recipes = new QPushButton("Recipes");
    QPushButton *backToGame = new QPushButton("Done");

    title_space = new QHBoxLayout();
    play_space = new QGridLayout();
    sandwich_layout = new QGridLayout();
    homeScreen = new QPushButton("Home Screen");
    homeScreen->setStyleSheet("QLabel { color : black }");

   /* QTimer* timer = new QTimer(this);
       connect(timer, SIGNAL(timeout()), this, SLOT(update()));
       timer->start(1000);*/

    QLabel* bread1 = new QLabel("White\nBread");
    bread1->setStyleSheet("QLabel { color : white }");
    QLabel* bread2 = new QLabel("Whole\nWheat\nBread");
    bread2->setStyleSheet("QLabel { color : white }");
    QLabel* bread3 = new QLabel("Pretzel\nBun");
    bread3->setStyleSheet("QLabel { color : white }");

    QLabel* cheese1 = new QLabel("American\nCheese");
    cheese1->setStyleSheet("QLabel { color : white }");
    QLabel* cheese2 = new QLabel("Swiss\nCheese");
    cheese2->setStyleSheet("QLabel { color : white }");
    QLabel* cheese3 = new QLabel("Vegan\nCheese");
    cheese3->setStyleSheet("QLabel { color : white }");

    QLabel* meat1 = new QLabel("Turkey\nMeat");
    meat1->setStyleSheet("QLabel { color : white }");
    QLabel* meat2 = new QLabel("Steak");
    meat2->setStyleSheet("QLabel { color : white }");
    QLabel* meat3 = new QLabel("Impossible\nMeat");
    meat3->setStyleSheet("QLabel { color : white }");

    QLabel* veggies1 = new QLabel("Lettuce");
    veggies1->setStyleSheet("QLabel { color : white }");
    QLabel* veggies2 = new QLabel("Peppers");
    veggies2->setStyleSheet("QLabel { color : white }");
    QLabel* veggies3 = new QLabel("Spinach");
    veggies3->setStyleSheet("QLabel { color : white }");

    text1 = new QLabel("Welcome to Heck's Kitchen!");
    text1->setStyleSheet("QLabel { color : black }");
    health_text = new QLabel("Health: "+ QString::number(health) );
    health_text->setStyleSheet("QLabel { color : black }");
    main_character = new Player;

    breadBin1 = new Bread_Bin(8,1);
    breadBin2 = new Bread_Bin(9,1);
    breadBin3 = new Bread_Bin(10,1);

    cheeseBin1 = new Cheese_Bin(11,2);
    cheeseBin2 = new Cheese_Bin(11,3);
    cheeseBin3 = new Cheese_Bin(11,4);

    meatBin1 = new Meat_Bin(9,5);
    meatBin2 = new Meat_Bin(10,5);
    meatBin3 = new Meat_Bin(11,5);

    veggieBin1 = new Veggie_Bin(6,7);
    veggieBin2 = new Veggie_Bin(7,7);
    veggieBin3 = new Veggie_Bin(8,7);

   // trash = new Bread_Bin(10, 3);

    //SET UP CUSTOMER
    customer1 = new Player(1,1,1);
    customer2 = new Player(1,2,2);
    customer3 = new Player(1,3,3);
    customer4 = new Player(1,4,4);
    order1 = new QPushButton ("Order 1");
    order2 = new QPushButton ("Order 2");
    order3 = new QPushButton ("Order 3");
    order4 = new QPushButton ("Order 4");
    connect(order1, SIGNAL(clicked()), this,SLOT(customer_order1()));
    connect(order2, SIGNAL(clicked()), this,SLOT(customer_order2()));
    connect(order3, SIGNAL(clicked()), this,SLOT(customer_order3()));
    connect(order4, SIGNAL(clicked()), this,SLOT(customer_order4()));
    connect(mute, SIGNAL(clicked()),this,SLOT(stop_music()));
    connect(recipes, SIGNAL(clicked()),this,SLOT(goToRecipes()));
    connect(backToGame, SIGNAL(clicked()),this,SLOT(goToSecondPage()));
    customer1->set_basic_sandwich();
    customer2->set_basic_sandwich();
    customer3->set_basic_sandwich();
    customer4->set_basic_sandwich();

    draw_walls();
    draw_targets();

    title_space->addWidget(text1);
    title_space->addWidget(health_text);
    title_space->addWidget(homeScreen);
    title_space->addWidget(mute);
    title_space->addWidget(recipes);

    play_space->addWidget(customer1,customer1->get_pos_y(),customer1->get_pos_x());
    play_space->addWidget(order1, customer1->get_pos_y(),customer1->get_pos_x()+1);
    play_space->addWidget(customer2,customer2->get_pos_y(),customer2->get_pos_x());
    play_space->addWidget(order2, customer2->get_pos_y(),customer2->get_pos_x()+1);
    play_space->addWidget(customer3,customer3->get_pos_y(),customer3->get_pos_x());
    play_space->addWidget(order3, customer3->get_pos_y(),customer3->get_pos_x()+1);
    play_space->addWidget(customer4,customer4->get_pos_y(),customer4->get_pos_x());
    play_space->addWidget(order4, customer4->get_pos_y(),customer4->get_pos_x()+1);

    play_space->addWidget(main_character, main_character->get_pos_y(),main_character->get_pos_x());

    play_space->addWidget(breadBin1,breadBin1->get_bin_pos_y(),breadBin1->get_bin_pos_x());
    play_space->addWidget(bread1,breadBin1->get_bin_pos_y(),breadBin1->get_bin_pos_x());

    play_space->addWidget(breadBin2,breadBin2->get_bin_pos_y(),breadBin2->get_bin_pos_x());
    play_space->addWidget(bread2,breadBin2->get_bin_pos_y(),breadBin2->get_bin_pos_x());

    play_space->addWidget(breadBin3,breadBin3->get_bin_pos_y(),breadBin3->get_bin_pos_x());
    play_space->addWidget(bread3,breadBin3->get_bin_pos_y(),breadBin3->get_bin_pos_x());

    play_space->addWidget(cheeseBin1,cheeseBin1->get_bin_pos_y(),cheeseBin1->get_bin_pos_x());
    play_space->addWidget(cheese1,cheeseBin1->get_bin_pos_y(),cheeseBin1->get_bin_pos_x());

    play_space->addWidget(cheeseBin2,cheeseBin2->get_bin_pos_y(),cheeseBin2->get_bin_pos_x());
    play_space->addWidget(cheese2,cheeseBin2->get_bin_pos_y(),cheeseBin2->get_bin_pos_x());

    play_space->addWidget(cheeseBin3,cheeseBin3->get_bin_pos_y(),cheeseBin3->get_bin_pos_x());
    play_space->addWidget(cheese3,cheeseBin3->get_bin_pos_y(),cheeseBin3->get_bin_pos_x());

    play_space->addWidget(meatBin1,meatBin1->get_bin_pos_y(),meatBin1->get_bin_pos_x());
    play_space->addWidget(meat1,meatBin1->get_bin_pos_y(),meatBin1->get_bin_pos_x());

    play_space->addWidget(meatBin2,meatBin2->get_bin_pos_y(),meatBin2->get_bin_pos_x());
    play_space->addWidget(meat2,meatBin2->get_bin_pos_y(),meatBin2->get_bin_pos_x());

    play_space->addWidget(meatBin3,meatBin3->get_bin_pos_y(),meatBin3->get_bin_pos_x());
    play_space->addWidget(meat3,meatBin3->get_bin_pos_y(),meatBin3->get_bin_pos_x());

    play_space->addWidget(veggieBin1,veggieBin1->get_bin_pos_y(),veggieBin1->get_bin_pos_x());
    play_space->addWidget(veggies1,veggieBin1->get_bin_pos_y(),veggieBin1->get_bin_pos_x());

    play_space->addWidget(veggieBin2,veggieBin2->get_bin_pos_y(),veggieBin2->get_bin_pos_x());
    play_space->addWidget(veggies2,veggieBin2->get_bin_pos_y(),veggieBin2->get_bin_pos_x());

    play_space->addWidget(veggieBin3,veggieBin3->get_bin_pos_y(),veggieBin3->get_bin_pos_x());
    play_space->addWidget(veggies3,veggieBin3->get_bin_pos_y(),veggieBin3->get_bin_pos_x());

   // play_space->addWidget(trash,trash->get_bin_pos_y(),trash->get_bin_pos_x());

    secondPage = new QWidget;
    fullwindow = new QVBoxLayout(secondPage);
    fullwindow->addLayout(title_space);
    fullwindow->addLayout(play_space);

    stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(secondPage);

    // window that shows when you win
    youWinPage = new QWidget;
    youWinPage->setStyleSheet("background-image: url(:/background.png)");
    youWinLayout = new QVBoxLayout(youWinPage);
    stackedWidget->addWidget(youWinPage);
    QLabel* win = new QLabel( "YOU WIN!");
    win->setStyleSheet("QLabel { color : black }");
    youWinLayout->addWidget(win);

    // window that shows when you lose
    youLosePage = new QWidget;
    youLosePage->setStyleSheet("background-image: url(:/background.png)");
    youLoseLayout = new QVBoxLayout(youLosePage);
    stackedWidget->addWidget(youLosePage);
    QLabel* lose = new QLabel( "YOU LOSE!");
    lose->setStyleSheet("QLabel { color : black }");
    youLoseLayout->addWidget(lose);

    // window that shows when you want to see sandwich recipes
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

void SecondWindow::stop_music(){
    if(music_mute%2 == 0){
    music->setMedia(QUrl("qrc:/easy music.mp3"));
    music->play();
    }
    else{
     music->pause();
    }
    music_mute++;
}

void SecondWindow::customer_order1() {
    QString  a = *customer1->print_sandwich();
    text1->setText("My order is the: " + a);
    //play_space->addWidget(text1,0,0);
    //customer1->test_print_sandwich();
    //fullwindow-> addLayout(customer1->print_sandwich());
    return;
}

void SecondWindow::customer_order2() {
    QString  a = *customer2->print_sandwich();
    text1->setText("My order is the: " + a);
    return;
}

void SecondWindow::customer_order3() {
    QString  a = *customer3->print_sandwich();
    text1->setText("My order is the: " + a);
    return;
}

void SecondWindow::customer_order4() {
    QString  a = *customer4->print_sandwich();
    text1->setText("My order is the: " + a);
    return;
}

void SecondWindow::draw_walls() {
    for (int i= 0; i<8; i++) {
        Wall* a= new Wall;
        play_space->addWidget(a,i,0);
    }
    for (int i= 0; i<8; i++) {
        Wall* a= new Wall;
        play_space->addWidget(a,i,16);
    }
    for (int i= 0; i<16; i++) {
        Wall* a= new Wall;
        play_space->addWidget(a,0,i);
    }
    for (int i= 0; i<16; i++) {
        Wall* a= new Wall;
        play_space->addWidget(a,8,i);
    }
}

void SecondWindow::draw_targets() {
    for (size_t i = 1; i < 8; i++) {
        Target* a = new Target;
        play_space->addWidget(a, i, 2);
    }
}

void SecondWindow::change_health(){
    health = health - 1;
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

void SecondWindow::goToRecipes() {
    stackedWidget->setCurrentIndex(3);
}

void SecondWindow::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_G && main_character->get_pos_x()-1==customer1->get_pos_x() && main_character->get_pos_y()==customer1->get_pos_y()) {
        main_character->print_sandwich();
        if (main_character->check_order(customer1) == true){
            people_served++;
            main_character->delete_sandwich();
            customer1->delete_sandwich();
            customer1->remove_event();
            if (people_served == 4) {
                goToWin();
            }
        } else {
            main_character->delete_sandwich();
            change_health();
            health_text->setText("Health: " + QString::number(health));
            if(health == 0) {
                goToLose();
            }
        }
    } else if(event->key() == Qt::Key_G && main_character->get_pos_x()-1==customer2->get_pos_x() && main_character->get_pos_y()==customer2->get_pos_y()) {
        main_character->print_sandwich();
        if (main_character->check_order(customer2) == true) {
            people_served++;
            main_character->delete_sandwich();
            customer2->delete_sandwich();
            customer2->remove_event();
            if (people_served == 4){
                goToWin();
            }
        } else {
            main_character->delete_sandwich();
            change_health();
            health_text->setText( "Health: " + QString::number(health));
            if(health == 0){
                goToLose();
            }
        }
    } else if(event->key() == Qt::Key_G && main_character->get_pos_x()-1==customer3->get_pos_x() &&main_character->get_pos_y()==customer3->get_pos_y()){
        main_character->print_sandwich();
        if (main_character->check_order(customer3) == true) {
           people_served++;
            main_character->delete_sandwich();
            customer3->delete_sandwich();
            customer3->remove_event();
            if (people_served == 4) {
                goToWin();
            }
        } else {
            main_character->delete_sandwich();
            change_health();
            health_text->setText("Health: " + QString::number(health));
            if(health == 0) {
                goToLose();
            }
        }
    } else if(event->key() == Qt::Key_G && main_character->get_pos_x()-1==customer4->get_pos_x() &&main_character->get_pos_y()==customer4->get_pos_y()) {
        main_character->print_sandwich();
        if (main_character->check_order(customer4) == true) {
            people_served++;
            main_character->delete_sandwich();
            customer4->delete_sandwich();
            customer4->remove_event();
            if (people_served == 4){
                goToWin();
            }
        } else {
            main_character->delete_sandwich();
            change_health();
            health_text->setText("Health: " + QString::number(health));
            if(health == 0){
                goToLose();
            }
        }
    } if (event->key() == Qt::Key_A||event->key() == Qt::Key_Left) {
        if (main_character->get_pos_x() > 2) {
            main_character->move_left();
            play_space->addWidget(main_character, main_character->get_pos_y(),main_character->get_pos_x());
        }
    } else if(event->key() == Qt::Key_D||event->key() == Qt::Key_Right) {
        if (main_character->get_pos_x() < 12) {
            main_character->move_right();
            play_space->addWidget(main_character, main_character->get_pos_y(),main_character->get_pos_x());
        }
    } else if(event->key() == Qt::Key_W||event->key() == Qt::Key_Up) {
        if (main_character->get_pos_y() > 0) {
            main_character->move_up();
            play_space->addWidget(main_character, main_character->get_pos_y(),main_character->get_pos_x());
        }
    }
    else if(event->key() == Qt::Key_S||event->key() == Qt::Key_Down) {
        if (main_character->get_pos_y() < 7) {
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
    return;
}

void SecondWindow::setPartner(QWidget* partner) {
    if (partner == 0)
        return;
    if (mPartner != partner) {
        if (mPartner != 0) {
            disconnect(homeScreen, SIGNAL(clicked()), this, SLOT(hide()));
            disconnect(homeScreen, SIGNAL(clicked()), mPartner, SLOT(showMaximized()));
        }
        mPartner = partner;
        connect(homeScreen, SIGNAL(clicked()), this, SLOT(hide()));
        connect(homeScreen, SIGNAL(clicked()), mPartner, SLOT(showMaximized()));
    }
}

SecondWindow::~SecondWindow(){
    delete main_character;
    delete customer1;
    /*delete customer2;
    delete customer3;
    delete customer4;*/
}
