#include "secondwindow.h"

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

    fullwindow = new QVBoxLayout();
    title_space = new QHBoxLayout();
    play_space = new QGridLayout();
    sandwich_layout = new QGridLayout();
    homeScreen = new QPushButton("Home Screen");
    homeScreen->setStyleSheet("QLabel { color : black }");

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

    this->setFixedSize(700,700);
    text1 = new QLabel("Welcome to Heck's Kitchen!");
    text1->setStyleSheet("QLabel { color : black }");
    health_text = new QLabel("Health: "+ QString::number(health) );
    health_text->setStyleSheet("QLabel { color : black }");
    main_character = new Player;
    breadBin1 = new Bread_Bin(9,1);
    breadBin2 = new Bread_Bin(10,1);
    breadBin3 = new Bread_Bin(11,1);

    cheeseBin1 = new Cheese_Bin(13,2);
    cheeseBin2 = new Cheese_Bin(13,3);
    cheeseBin3 = new Cheese_Bin(13,4);

    meatBin1 = new Meat_Bin(9,5);
    meatBin2 = new Meat_Bin(10,5);
    meatBin3 = new Meat_Bin(11,5);

    veggieBin1 = new Veggie_Bin(7,7);
    veggieBin2 = new Veggie_Bin(9,7);
    veggieBin3 = new Veggie_Bin(10,7);

    //SET UP CUSTOMER
    customer1 = new Player(1,1);
    customer2 = new Player(1,2);
    customer3 = new Player(1,3);
    customer4 = new Player(1,4);
    order1 = new QPushButton ("Order 1");
    order2 = new QPushButton ("Order 2");
    order3 = new QPushButton ("Order 3");
    order4 = new QPushButton ("Order 4");
    connect(order1, SIGNAL(clicked()), this,SLOT(customer_order1()));
    connect(order2, SIGNAL(clicked()), this,SLOT(customer_order2()));
    connect(order3, SIGNAL(clicked()), this,SLOT(customer_order3()));
    connect(order4, SIGNAL(clicked()), this,SLOT(customer_order4()));
    customer1->set_basic_sandwich();
    customer2->set_basic_sandwich();
    customer3->set_basic_sandwich();
    customer4->set_basic_sandwich();

    draw_walls();
    draw_targets();

    title_space->addWidget(text1);
    title_space->addWidget(health_text);
    title_space->addWidget(homeScreen);

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

    fullwindow->addLayout(title_space);
    fullwindow->addLayout(play_space);
    //fullwindow->addLayout(sandwich_layout);
    setLayout(fullwindow);
}

void SecondWindow::customer_order1() {
    customer1->test_print_sandwich();
    //fullwindow-> addLayout(customer1->print_sandwich());
    return;
}

void SecondWindow::customer_order2() {
    customer2->test_print_sandwich();
   // fullwindow-> addLayout(customer2->print_sandwich());
    return;
}

void SecondWindow::customer_order3() {
     customer3->test_print_sandwich();
   // fullwindow-> addLayout(customer3->print_sandwich());
    return;
}

void SecondWindow::customer_order4() {
     customer4->test_print_sandwich();
    //fullwindow-> addLayout(customer4->print_sandwich());
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

void SecondWindow::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_G && main_character->get_pos_x()-1==customer1->get_pos_x() && main_character->get_pos_y()==customer1->get_pos_y()) {
        main_character->print_sandwich();
        if (main_character->check_order(customer1) == true){
            QLabel* winner = new QLabel( "You win the game!!");
            winner->show();
            main_character->delete_sandwich();
            customer1->delete_sandwich();
            customer1->remove_event();
        } else {
            QLabel* looser = new QLabel( "You Lost!!");
            looser->show();
            main_character->delete_sandwich();
        }
    } else if(event->key() == Qt::Key_G && main_character->get_pos_x()-1==customer2->get_pos_x() && main_character->get_pos_y()==customer2->get_pos_y()) {
        main_character->print_sandwich();
        if (main_character->check_order(customer2) == true) {
            QLabel* winner = new QLabel( "You win the game!!");
            winner->show();
            main_character->delete_sandwich();
            customer2->delete_sandwich();
            customer2->remove_event();
        } else {
            QLabel* looser = new QLabel( "You Lost!!");
            looser->show();
            main_character->delete_sandwich();
        }
    } else if(event->key() == Qt::Key_G && main_character->get_pos_x()-1==customer3->get_pos_x() &&main_character->get_pos_y()==customer3->get_pos_y()){
        main_character->print_sandwich();
        if (main_character->check_order(customer3) == true) {
            QLabel* winner = new QLabel( "You win the game!!");
            winner->show();
            main_character->delete_sandwich();
            customer3->delete_sandwich();
            customer3->remove_event();
        } else {
            QLabel* looser = new QLabel( "You Lost!!");
            looser->show();
            main_character->delete_sandwich();
        }
    } else if(event->key() == Qt::Key_G && main_character->get_pos_x()-1==customer4->get_pos_x() &&main_character->get_pos_y()==customer4->get_pos_y()) {
        main_character->print_sandwich();
        if (main_character->check_order(customer4) == true) {
            QLabel* winner = new QLabel("You win the game!!");
            winner->show();
            main_character->delete_sandwich();
            customer4->delete_sandwich();
            customer4->remove_event();
        } else {
            QLabel* looser = new QLabel("You Lost!!");
            looser->show();
            main_character->delete_sandwich();
        }
    } if (event->key() == Qt::Key_A||event->key() == Qt::Key_Left) {
        if (main_character->get_pos_x() > 2) {
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
    }
    else if(event->key() == Qt::Key_S||event->key() == Qt::Key_Down) {
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
            Food* a = new Veggies("Spinage");
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
