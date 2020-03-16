#include "secondwindow.h"
#include <QString>
#include <iostream>

SecondWindow::SecondWindow(QWidget *parent)
    : QWidget(parent)
{
    this->setFixedSize(875,700);
    move(300,50);

    QPixmap bkgnd(":/main.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    setFocusPolicy(Qt::ClickFocus);
    QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    music = new QMediaPlayer;
    music->setParent(this);

    title_space = new QHBoxLayout;
    play_space = new QGridLayout;

    // Button to mute music
    mute = new QPushButton;
    QPixmap mutePix(":/music.png");
    mutePix = mutePix.scaled(102, 60, Qt::KeepAspectRatio, Qt::FastTransformation);
    QIcon muteIcon(mutePix);
    mute->setIcon(muteIcon);
    mute->setIconSize(mutePix.rect().size());
    mute->setFixedSize(mutePix.rect().size());

    // Button to see sandwich recipes
    toRecipes = new QPushButton;
    QPixmap recipesPix(":/recipes.png");
    recipesPix = recipesPix.scaled(125, 60, Qt::KeepAspectRatio, Qt::FastTransformation);
    QIcon recipesIcon(recipesPix);
    toRecipes->setIcon(recipesIcon);
    toRecipes->setIconSize(recipesPix.rect().size());
    toRecipes->setFixedSize(recipesPix.rect().size());

    // Button to go back to home screen
    toHome = new QPushButton;
    QPixmap homePix(":/home.png");
    homePix = homePix.scaled(100, 60, Qt::KeepAspectRatio, Qt::FastTransformation);
    QIcon homeIcon(homePix);
    toHome->setIcon(homeIcon);
    toHome->setIconSize(homePix.rect().size());
    toHome->setFixedSize(homePix.rect().size());

    game_text = new QLabel("Welcome to Heck's Kitchen!");
    game_text->setAlignment(Qt::AlignCenter);
    game_text->setFixedWidth(250);
    game_text->setFixedHeight(45);
    game_text->setStyleSheet("QLabel { color : black }");
    rating_text = new QLabel("Rating: "+ QString::number(rating));
    rating_text->setFixedWidth(100);
    rating_text->setStyleSheet("QLabel { color : black; font-size: 18px; }");

    timeLabel = new QLabel;
    timeLabel->setFixedWidth(50);
    timeLabel->setStyleSheet("QLabel { color : black; font-weight : bold; font-size: 20px;height: 30px; width: 80px }");

    player_rating = new Rating;
    main_character = new Player;

    // Creates food bins, sets their name and position
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

    title_space->addWidget(game_text);
    title_space->setSpacing(15);
    title_space->addWidget(rating_text);
    title_space->addWidget(player_rating);
    title_space->addWidget(toHome);
    title_space->addWidget(mute);
    title_space->addWidget(toRecipes);

    play_space->addWidget(timeLabel, 1,1);

    QSpacerItem* one = new QSpacerItem(300, 300, QSizePolicy::Fixed, QSizePolicy::Fixed);
    play_space->addItem(one, 1, 1, 1, 13);
    QSpacerItem* two = new QSpacerItem(45, 45, QSizePolicy::Fixed, QSizePolicy::Fixed);
    play_space->addItem(two, 2, 1, 1, 13);
    QSpacerItem* three = new QSpacerItem(45, 45, QSizePolicy::Fixed, QSizePolicy::Fixed);
    play_space->addItem(three, 3, 1, 1, 13);
    QSpacerItem* four = new QSpacerItem(45, 45, QSizePolicy::Fixed, QSizePolicy::Fixed);
    play_space->addItem(four, 4, 1, 1, 13);
    QSpacerItem* five = new QSpacerItem(45, 45, QSizePolicy::Fixed, QSizePolicy::Fixed);
    play_space->addItem(five, 5, 1, 1, 13);
    QSpacerItem* six = new QSpacerItem(45, 45, QSizePolicy::Fixed, QSizePolicy::Fixed);
    play_space->addItem(six, 6, 1, 1, 13);
    QSpacerItem* seven = new QSpacerItem(45, 45, QSizePolicy::Fixed, QSizePolicy::Fixed);
    play_space->addItem(seven, 7, 1, 1, 13);
    QSpacerItem* eight = new QSpacerItem(45, 45, QSizePolicy::Fixed, QSizePolicy::Fixed);
    play_space->addItem(eight, 8, 1, 1, 13);
    QSpacerItem* nine = new QSpacerItem(45, 45, QSizePolicy::Fixed, QSizePolicy::Fixed);
    play_space->addItem(nine, 9, 1, 1, 13);
    QSpacerItem* ten = new QSpacerItem(250, 250, QSizePolicy::Fixed, QSizePolicy::Fixed);
    play_space->addItem(ten, 10, 1, 1, 13);

    // Places breads
    play_space->addWidget(breadBin1,breadBin1->get_bin_pos_y(),breadBin1->get_bin_pos_x());
    play_space->addWidget(breadBin2,breadBin2->get_bin_pos_y(),breadBin2->get_bin_pos_x());
    play_space->addWidget(breadBin3,breadBin3->get_bin_pos_y(),breadBin3->get_bin_pos_x());
    // Places cheeses
    play_space->addWidget(cheeseBin1,cheeseBin1->get_bin_pos_y(),cheeseBin1->get_bin_pos_x());
    play_space->addWidget(cheeseBin2,cheeseBin2->get_bin_pos_y(),cheeseBin2->get_bin_pos_x());
    play_space->addWidget(cheeseBin3,cheeseBin3->get_bin_pos_y(),cheeseBin3->get_bin_pos_x());
    // Places protein
    play_space->addWidget(meatBin1,meatBin1->get_bin_pos_y(),meatBin1->get_bin_pos_x());
    play_space->addWidget(meatBin2,meatBin2->get_bin_pos_y(),meatBin2->get_bin_pos_x());
    play_space->addWidget(meatBin3,meatBin3->get_bin_pos_y(),meatBin3->get_bin_pos_x());
    // Places veggies
    play_space->addWidget(veggieBin1,veggieBin1->get_bin_pos_y(),veggieBin1->get_bin_pos_x());
    play_space->addWidget(veggieBin2,veggieBin2->get_bin_pos_y(),veggieBin2->get_bin_pos_x());
    play_space->addWidget(veggieBin3,veggieBin3->get_bin_pos_y(),veggieBin3->get_bin_pos_x());
    // Places trash can
    play_space->addWidget(trash,trash->get_bin_pos_y(),trash->get_bin_pos_x());
    play_space->addWidget(trash2,trash2->get_bin_pos_y(),trash2->get_bin_pos_x());

    actual_game_timer = new QTimer;
    actual_game_timer->setParent(this);

    fullwindow = new QVBoxLayout;
    fullwindow->addLayout(title_space);
    fullwindow->addLayout(play_space);
    this->setLayout(fullwindow); // Memory Management, everything is now owned by MainWindow!

    begin_game();
}

void SecondWindow::begin_game() {
    music = new QMediaPlayer(this);
    /* Depending on the challenge rating,
     * this will play the corresponding music file */
    if(difficulty_level == 1){
        music->setMedia(QUrl("qrc:/easy music.mp3"));
    } else if(difficulty_level == 2){
        music->setMedia(QUrl("qrc:/medium music.mp3"));
    } else{
        music->setMedia(QUrl("qrc:/hard music.mp3"));
    } stop_music();
    game_text->setText("Welcome to Heck's Kitchen");
    people_served = 0;
    rating = 100;
    rating_text->setText("Rating: " + QString::number(rating));
    puddle1 = new Puddle(1,1);
    puddle2 = new Puddle(0,0);
    fire1 = new Fire(2,2);
    player_rating->reset_rating();
    if (difficulty_level >=2) { // For level 2 and 3, add puddles
        puddle1 = puddle1->set_random_location();
        play_space->addWidget(puddle1,puddle1->get_bin_pos_y(),puddle1->get_bin_pos_x());
    } if(difficulty_level>=3) { // For level 3, add puddles and fire
        puddle2 = puddle2->set_random_location();
        /* Checks if the puddles share the same space - if they do, it will run again and again until they do not */
        while(puddle1->get_bin_pos_y()==puddle2->get_bin_pos_y() && puddle2->get_bin_pos_x()==puddle1->get_bin_pos_x()) {
            puddle2 = puddle2->set_random_location();
        } play_space->addWidget(puddle2,puddle2->get_bin_pos_y(),puddle2->get_bin_pos_x());
        fire1 = fire1->set_random_location();
        play_space->addWidget(fire1,fire1->get_bin_pos_y(),fire1->get_bin_pos_x());
    }

    // Creates characters and sets their positions
    main_character = new Player;
    play_space->addWidget(main_character, main_character->get_pos_y(),main_character->get_pos_x());
    customer1 = new Player(1,3,1);
    customer2 = new Player(1,4,2);
    customer3 = new Player(1,5,3);
    customer4 = new Player(1,6,4);
    customer5 = new Player(1,7,2);
    customer6 = new Player(1,8,3);
    customer7 = new Player(1,9,2);

    QSpacerItem* hor = new QSpacerItem(75, 75, QSizePolicy::Fixed, QSizePolicy::Fixed);
    play_space->addItem(hor, 1, 1, 10, 1);

    // Order buttons
    order1 = new QPushButton;
    QPixmap order1Pix(":/order1.png");
    order1Pix = order1Pix.scaled(40, 30, Qt::KeepAspectRatio, Qt::FastTransformation);
    order1->setIcon(order1Pix);
    order1->setIconSize(order1Pix.rect().size());
    order1->setFixedSize(order1Pix.rect().size());

    order2 = new QPushButton;
    QPixmap order2Pix(":/order2.png");
    order2Pix = order2Pix.scaled(40, 30, Qt::KeepAspectRatio, Qt::FastTransformation);
    order2->setIcon(order2Pix);
    order2->setIconSize(order2Pix.rect().size());
    order2->setFixedSize(order2Pix.rect().size());

    order3 = new QPushButton;
    QPixmap order3Pix(":/order3.png");
    order3Pix = order3Pix.scaled(40, 30, Qt::KeepAspectRatio, Qt::FastTransformation);
    order3->setIcon(order3Pix);
    order3->setIconSize(order3Pix.rect().size());
    order3->setFixedSize(order3Pix.rect().size());

    order4 = new QPushButton;
    QPixmap order4Pix(":/order4.png");
    order4Pix = order4Pix.scaled(40, 30, Qt::KeepAspectRatio, Qt::FastTransformation);
    order4->setIcon(order4Pix);
    order4->setIconSize(order4Pix.rect().size());
    order4->setFixedSize(order4Pix.rect().size());

    order5 = new QPushButton;
    order6 = new QPushButton;
    order7 = new QPushButton;

    customer1->create_event();
    customer_setup();
}

void SecondWindow::customer_setup(){
    /* Adds additional customers, depending on the level, to the grid */
    if(difficulty_level >= 1){ // If level 1, only have 4 customers
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
    } if(difficulty_level >= 2) {
        customer5 = new Player(1,7,2);
        customer6 = new Player(1,8,3);
        order5 = new QPushButton;
        QPixmap order5Pix(":/order5.png");
        order5Pix = order5Pix.scaled(40, 30, Qt::KeepAspectRatio, Qt::FastTransformation);
        order5->setIcon(order5Pix);
        order5->setIconSize(order5Pix.rect().size());
        order5->setFixedSize(order5Pix.rect().size());

        order6 = new QPushButton;
        QPixmap order6Pix(":/order6.png");
        order6Pix = order6Pix.scaled(40, 30, Qt::KeepAspectRatio, Qt::FastTransformation);
        order6->setIcon(order6Pix);
        order6->setIconSize(order6Pix.rect().size());
        order6->setFixedSize(order6Pix.rect().size());

        play_space->addWidget(customer5,customer5->get_pos_y(),customer5->get_pos_x());
        play_space->addWidget(order5, customer5->get_pos_y(),customer5->get_pos_x()+1);
        play_space->addWidget(customer6,customer6->get_pos_y(),customer6->get_pos_x());
        play_space->addWidget(order6, customer6->get_pos_y(),customer6->get_pos_x()+1);
        connect(order5, SIGNAL(clicked()), this,SLOT(customer_order5()));
        connect(order6, SIGNAL(clicked()), this,SLOT(customer_order6()));
    } if (difficulty_level >=3 ) {
        customer7 = new Player(1,9,2);
        order7 = new QPushButton;
        QPixmap order7Pix(":/order7.png");
        order7Pix = order7Pix.scaled(40, 30, Qt::KeepAspectRatio, Qt::FastTransformation);
        order7->setIcon(order7Pix);
        order7->setIconSize(order7Pix.rect().size());
        order7->setFixedSize(order7Pix.rect().size());
        play_space->addWidget(customer7,customer7->get_pos_y(),customer7->get_pos_x());
        play_space->addWidget(order7, customer7->get_pos_y(),customer7->get_pos_x()+1);
        connect(order7, SIGNAL(clicked()), this,SLOT(customer_order7()));
   /* Depending on the level, sets type/difficulty of sandwiches that the customers order */
    } if (difficulty_level == 1) {
        customer1->set_basic_sandwich();
        customer2->set_basic_sandwich();
        customer3->set_basic_sandwich();
        customer4->set_basic_sandwich();
    } else if(difficulty_level == 2) {
        customer1->set_basic_sandwich();
        customer2->set_intermediate_sandwich();
        customer3->set_expert_sandwich();
        customer4->set_intermediate_sandwich();
        customer5->set_basic_sandwich();
        customer6->set_intermediate_sandwich();
    } else if(difficulty_level == 3) {
        customer1->set_expert_sandwich();
        customer2->set_intermediate_sandwich();
        customer3->set_basic_sandwich();
        customer4->set_expert_sandwich();
        customer5->set_intermediate_sandwich();
        customer6->set_intermediate_sandwich();
        customer7->set_expert_sandwich();
    }
}

void SecondWindow::reset_game() {
    delete_game();
    this->hide();
    actual_game_timer->stop();
    begin_game();
}

// Destructor
void SecondWindow::delete_game() {
    customer1->remove_event();
    customer2->remove_event();
    customer3->remove_event();
    customer4->remove_event();
    customer5->remove_event();
    customer6->remove_event();
    customer7->remove_event();
    delete music;
    music_mute = 0;
    delete main_character;
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
    delete puddle2;
    delete fire1;
}

void SecondWindow::stop_music() {
    /* If the value of music_mute % 2 is zero, play the music, otherwise stop the music */
    if (music_mute%2 == 0) {
        music->play();
    } else {
           music->pause();
    } music_mute++;
}

void SecondWindow::start_timer() {
    actual_game_timer->setInterval(150000);
    actual_game_timer->setSingleShot(true);
    connect(actual_game_timer, SIGNAL(timeout()), this, SLOT(loseConditionSatisfied()));
    actual_game_timer->start();

    time_display.start();
    updateTime();
    connect(&timer_display, SIGNAL(timeout()), this, SLOT(updateTime()));
    timer_display.start(500); // twice per second
}

void SecondWindow::updateTime() {
    int secs = time_display.elapsed() / 1000;
    int mins = (secs / 60) % 60;
    secs = secs % 60;
    timeLabel->setText(QString("%2:%3")
                       .arg(mins, 2, 10, QLatin1Char(' '))
                       .arg(secs, 2, 10, QLatin1Char('0')) );
}

void SecondWindow::customer_order1() {
    QString  a = *customer1->get_sandwich_name();
    game_text->setText("My order is: " + a);
    return;
}

void SecondWindow::customer_order2() {
    QString  a = *customer2->get_sandwich_name();
    game_text->setText("My order is: " + a);
    return;
}

void SecondWindow::customer_order3() {
    QString  a = *customer3->get_sandwich_name();
    game_text->setText("My order is: " + a);
    return;
}
void SecondWindow::customer_order4() {
    QString  a = *customer4->get_sandwich_name();
    game_text->setText("My order is: " + a);
    return;
}

void SecondWindow::customer_order5() {
    QString  a = *customer5->get_sandwich_name();
    game_text->setText("My order is: " + a);
    return;
}

void SecondWindow::customer_order6() {
    QString  a = *customer6->get_sandwich_name();
    game_text->setText("My order is: " + a);
    return;
}

void SecondWindow::customer_order7() {
    QString  a = *customer7->get_sandwich_name();
    game_text->setText("My order is: " + a);
    return;
}

void SecondWindow::decrease_rating() {
    rating = rating - 10;
}

void SecondWindow::set_difficulty_level_w2(const int& a) {
    difficulty_level = a;
}

void SecondWindow:: faceRight() { main_character->turnRight(); }

void SecondWindow::faceLeft() { main_character->turnLeft(); }

void SecondWindow::keyPressEvent(QKeyEvent *event) {
   /* If 'A' key or Left arrow key is pressed, the player will
    * move one space on the grid to the left and face left */
    if (event->key() == Qt::Key_A || event->key() == Qt::Key_Left) {
        if (main_character->get_pos_x() > 3) {
            main_character->move_left();
            play_space->addWidget(main_character, main_character->get_pos_y(),main_character->get_pos_x());
            faceLeft();
        }
   /* If 'D' key or Right arrow key is pressed, the player will
    * move one space on the grid to the Right and face Right */
    } else if(event->key() == Qt::Key_D||event->key() == Qt::Key_Right) {
        if (main_character->get_pos_x() < 11) {
            main_character->move_right();
            play_space->addWidget(main_character, main_character->get_pos_y(),main_character->get_pos_x());
            faceRight();
        }
   /* If 'W' key or Up arrow key is pressed,
    * the player will move one space up on the grid */
    } else if(event->key() == Qt::Key_W||event->key() == Qt::Key_Up) {
        if (main_character->get_pos_y() > 2) {
            main_character->move_up();
            play_space->addWidget(main_character, main_character->get_pos_y(),main_character->get_pos_x());
        }
    }
   /* If 'S' key or Down arrow key is pressed,
    * the player will move one space down on the grid down */
    else if(event->key() == Qt::Key_S||event->key() == Qt::Key_Down) {
        if (main_character->get_pos_y() < 9) {
            main_character->move_down();
            play_space->addWidget(main_character, main_character->get_pos_y(),main_character->get_pos_x());
        }
    }
    /* SPACE key picks up food if the player is in the same position as the respective food bin */
    if (event->key() == Qt::Key_Space) {
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
   /* Clears the sandwich vector when player is touching the trash bin */
    if (main_character->get_pos_x() == trash->get_bin_pos_x() && main_character->get_pos_y()==trash->get_bin_pos_y()) {
        main_character->delete_sandwich();
    } if (main_character->get_pos_x() == trash2->get_bin_pos_x() && main_character->get_pos_y()==trash2->get_bin_pos_y()) {
        main_character->delete_sandwich();
   /* Clears the sandwich vector and deducts from restaurant rating if the player touches the puddle */
    } if(main_character->get_pos_x() == puddle1->get_bin_pos_x() && main_character->get_pos_y()==puddle1->get_bin_pos_y()) {
        main_character->delete_sandwich();
        player_rating->change_rating_bar(2);
        rating -= 2;
        rating_text->setText("Rating: " + QString::number(rating));
        if(rating <= 0) { loseConditionSatisfied(); }
        game_text->setText("Oops! I slipped!");
    } if (main_character->get_pos_x() == puddle2->get_bin_pos_x() && main_character->get_pos_y()==puddle2->get_bin_pos_y()){
            main_character->delete_sandwich();
            player_rating->change_rating_bar(2);
            rating -= 2;
            rating_text->setText("Rating: " + QString::number(rating));
            if(rating <= 0) { loseConditionSatisfied(); }
            game_text->setText("Oops! I slipped!");}
     /* Deducts from restaurant rating if the player touches the fire*/
    if (main_character->get_pos_x() == fire1->get_bin_pos_x() && main_character->get_pos_y()==fire1->get_bin_pos_y()) {
        game_text->setText(" Ow!!");
        player_rating->change_rating_bar(50);
        rating -= 50;
        rating_text->setText("Rating: " + QString::number(rating));
        if(rating <= 0){ loseConditionSatisfied(); }
    }

   /* 'G' key serves sandwiches if the player position is next to the order button they want to complete */
    if(event->key() == Qt::Key_G) {
        if (main_character->get_pos_x()-2 == customer1->get_pos_x()
            && main_character->get_pos_y()==customer1->get_pos_y() && customer1->check_presence()) {
            main_character->get_sandwich_name();
            /* Checks if the customer's order matches that of the main character's sandwich vector. If it does,
             * they successfully serve and remove that customer. If not, they will lose rating. In all cases,
             * their sandwich vector is cleared */
            if (main_character->check_order(customer1)) {
                people_served++;
                main_character->delete_sandwich();
                game_text->setText("Thanks!!");
                customer1->remove_event();
                order1->hide();
            } else {
                main_character->delete_sandwich();
                decrease_rating();
                game_text->setText("Oh... that isn't what I asked for");
                player_rating->change_rating_bar(10);
                rating_text->setText("Rating: " + QString::number(rating));
            }
        }
        /* Same process for all customers */
        else if( main_character->get_pos_x()-2 == customer2->get_pos_x() && main_character->get_pos_y()==customer2->get_pos_y()&& customer2->check_presence()) {
            main_character->get_sandwich_name();
            if (main_character->check_order(customer2)) {
                people_served++;
                main_character->delete_sandwich();
                game_text->setText("Thanks!!");
                customer2->remove_event();
                order2->hide();
            } else {
                main_character->delete_sandwich();
                decrease_rating();
                game_text->setText("Um...why'd they hire you?");
                player_rating->change_rating_bar(10);
                rating_text->setText("Rating: " + QString::number(rating));
            }
        } else if( main_character->get_pos_x()-2 == customer3->get_pos_x() &&main_character->get_pos_y()==customer3->get_pos_y()&& customer3->check_presence()){
            main_character->get_sandwich_name();
            if (main_character->check_order(customer3)) {
                people_served++;
                main_character->delete_sandwich();
                customer3->remove_event();
                order3->hide();
                game_text->setText("Perfect! Thank you!");
            } else {
                main_character->delete_sandwich();
                decrease_rating();
                rating_text->setText("Rating: " + QString::number(rating));
                player_rating->change_rating_bar(10);
                game_text->setText("Um, No, Try again");
            }
        } else if( main_character->get_pos_x()-2 == customer4->get_pos_x() &&main_character->get_pos_y()==customer4->get_pos_y()&& customer4->check_presence()) {
            main_character->get_sandwich_name();
            if (main_character->check_order(customer4)) {
                people_served++;
                main_character->delete_sandwich();
                customer4->remove_event();
                order4->hide();
                game_text->setText("Yum!!! Thanks!");
            } else {
                main_character->delete_sandwich();
                decrease_rating();
                rating_text->setText("Rating: " + QString::number(rating));
                player_rating->change_rating_bar(10);
                game_text->setText("Oh... that isn't what I asked for");
            }
        } else if( main_character->get_pos_x()-2 == customer5->get_pos_x() &&main_character->get_pos_y()==customer5->get_pos_y()&& customer5->check_presence()) {
            main_character->get_sandwich_name();
            if (main_character->check_order(customer5)) {
                people_served++;
                main_character->delete_sandwich();
                customer5->remove_event();
                order5->hide();
                game_text->setText("Wow! Looks Great!");
            } else {
                main_character->delete_sandwich();
                decrease_rating();
                rating_text->setText("Rating: " + QString::number(rating));
                player_rating->change_rating_bar(10);
                game_text->setText("Hmm you aren't very good at this, hm?");
            }
        } else if( main_character->get_pos_x()-2 == customer6->get_pos_x() &&main_character->get_pos_y()==customer6->get_pos_y()&& customer6->check_presence()) {
            main_character->get_sandwich_name();
            if (main_character->check_order(customer6)) {
                people_served++;
                main_character->delete_sandwich();
                customer6->remove_event();
                order6->hide();
                game_text->setText("Perfect! Thanks!");
            } else {
                main_character->delete_sandwich();
                decrease_rating();
                rating_text->setText("Rating: " + QString::number(rating));
                player_rating->change_rating_bar(10);
                game_text->setText("Oh... that isn't what I asked for");
            }
        } else if( main_character->get_pos_x()-2 == customer7->get_pos_x() &&main_character->get_pos_y()==customer7->get_pos_y()&& customer7->check_presence()) {
            main_character->get_sandwich_name();
            if (main_character->check_order(customer7)) {
                people_served++;
                main_character->delete_sandwich();
                customer7->remove_event();
                order7->hide();
                game_text->setText("Yum! Thanks!");
            } else {
                main_character->delete_sandwich();
                decrease_rating();
                player_rating->change_rating_bar(10);
                rating_text->setText("Rating: " + QString::number(rating));
                game_text->setText("No, no, that isn't right");
            }
        /* After the 'G' key is pressed, checks if the win conditions have been satisfied
         * - if enough customers were served depending on the level */
        } if (difficulty_level == 1 && people_served == 4) {
            winConditionSatisfied();
        } else if (difficulty_level== 2 && people_served == 6) {
            winConditionSatisfied();
        } else if (difficulty_level== 3 && people_served == 7) {
            winConditionSatisfied();
        }
         /* Additionally, it checks the rating too, and if that hits zero, they also lose */
        if (rating <= 0) {loseConditionSatisfied();}
    }
    return;
}

void SecondWindow::setPartner(QWidget* partner, RecipeWindow* partner2, Lose* partner3, Win* partner4) {
    mPartner = partner;
    connect(toHome, SIGNAL(clicked()), this, SLOT(reset_game()));
    connect(toHome, SIGNAL(clicked()), mPartner, SLOT(showMaximized()));
    mPartner2 = partner2;
    connect(toRecipes, SIGNAL(clicked()), this, SLOT(hide()));
    connect(toRecipes, SIGNAL(clicked()), mPartner2, SLOT(showMaximized()));
    mPartner3 = partner3;
    connect(this, SIGNAL(loseCondition()), this, SLOT(reset_game()));
    connect(this, SIGNAL(loseCondition()), mPartner3, SLOT(showMaximized()));
    mPartner4 = partner4;
    connect(this, SIGNAL(winCondition()), this, SLOT(reset_game()));
    connect(this, SIGNAL(winCondition()), mPartner4, SLOT(showMaximized()));
}

SecondWindow::~SecondWindow() {}

RecipeWindow::RecipeWindow(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(875,700);
    move(300,50);
    QPixmap recipes1(":/recipes1.png");
    recipes1 = recipes1.scaled(this->size(), Qt::IgnoreAspectRatio);
    recipebkgnd.setBrush(QPalette::Background, recipes1);
    this->setPalette(recipebkgnd);

    buttonLayout= new QGridLayout;

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

void RecipeWindow::goForward() {
   /* If recipe Counter is 4 - meaning that the player is on the
    * last page of the recipe book - the 'next button will be hidden */
    if (recipeCounter == 4) {
        recipeForward->hide();
        return;
    } /* Otherwise, it will flip to the next respective pages and show the buttons needed for them */
    else if (recipeCounter == 1) {
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

void RecipeWindow::goBack() {
   /* If recipe Counter is 1 - meaning that the player is on the
    * first page of the recipe book - the 'previous' button will be hidden */
    if (recipeCounter == 1) {
        recipeBack->hide();
        return;
    } /* The way the counter works, the button will also need to be hidden when it is two */
    else if (recipeCounter == 2) {
        recipeBack->hide();
        --recipeCounter;
        QPixmap recipes1(":/recipes1.png");
        recipes1 = recipes1.scaled(this->size(), Qt::IgnoreAspectRatio);
        recipebkgnd.setBrush(QPalette::Background, recipes1);
        this->setPalette(recipebkgnd);
    }
    else if (recipeCounter == 3) {
        --recipeCounter;
        QPixmap recipes2(":/recipes2.png");
        recipes2 = recipes2.scaled(this->size(), Qt::IgnoreAspectRatio);
        recipebkgnd.setBrush(QPalette::Background, recipes2);
        this->setPalette(recipebkgnd);
    }
    else if (recipeCounter == 4) {
        recipeForward->show();
        --recipeCounter;
        QPixmap recipes3(":/recipes3.png");
        recipes3 = recipes3.scaled(this->size(), Qt::IgnoreAspectRatio);
        recipebkgnd.setBrush(QPalette::Background, recipes3);
        this->setPalette(recipebkgnd);
    }
}

void RecipeWindow::setPartner2(SecondWindow* partner) {
    mPartner2 = partner;
    connect(toSecondW, SIGNAL(clicked()), this, SLOT(hide()));
    connect(toSecondW, SIGNAL(clicked()), mPartner2, SLOT(showMaximized()));
}

RecipeWindow::~ RecipeWindow() {}

// 'You're Fired' screen
Lose::Lose(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(875,700);
    move(300,50);
    QPixmap losePix(":/losescreen.png");
    losePix = losePix.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette loseBkgnd;
    loseBkgnd.setBrush(QPalette::Background, losePix);
    this->setPalette(loseBkgnd);

    backToHome = new QPushButton;
    QPixmap backToHomePix(":/back.png");
    backToHomePix = backToHomePix.scaled(650, 500, Qt::KeepAspectRatio, Qt::FastTransformation);
    backToHome->setIcon(backToHomePix);
    backToHome->setIconSize(backToHomePix.rect().size());
    backToHome->setFixedSize(backToHomePix.rect().size());
    QSpacerItem* top = new QSpacerItem(300, 600, QSizePolicy::Maximum, QSizePolicy::Maximum);
    QVBoxLayout* pageLayout = new QVBoxLayout;
    pageLayout->addItem(top);
    pageLayout->addWidget(backToHome);
    pageLayout->setAlignment(backToHome, Qt::AlignHCenter);
    setLayout(pageLayout);

}

Lose::~Lose(){};

void Lose::setPartner3(QWidget* partner) {
    mPartner3 = partner;
    connect(backToHome, SIGNAL(clicked()), this, SLOT(hide()));
    connect(backToHome, SIGNAL(clicked()), mPartner3, SLOT(showMaximized()));
}

// 'You've Been Promoted' screen
Win::Win(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(875,700);
    move(300,50);
    QPixmap winPix(":/winscreen.png");
    winPix = winPix.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette winBkgnd;
    winBkgnd.setBrush(QPalette::Background, winPix);
    this->setPalette(winBkgnd);
    backToHome = new QPushButton;
    QPixmap backToHomePix(":/back.png");
    backToHomePix = backToHomePix.scaled(650, 500, Qt::KeepAspectRatio, Qt::FastTransformation);
    backToHome->setIcon(backToHomePix);
    backToHome->setIconSize(backToHomePix.rect().size());
    backToHome->setFixedSize(backToHomePix.rect().size());
    QSpacerItem* top = new QSpacerItem(300, 600, QSizePolicy::Maximum, QSizePolicy::Maximum);
    QVBoxLayout* pageLayout = new QVBoxLayout;
    pageLayout->addItem(top);
    pageLayout->addWidget(backToHome);
    pageLayout->setAlignment(backToHome, Qt::AlignHCenter);
    this->setLayout(pageLayout);
}

Win::~Win(){};

void Win::setPartner4(QWidget* partner){
    mPartner4 = partner;
    connect(backToHome, SIGNAL(clicked()), this, SLOT(hide()));
    connect(backToHome, SIGNAL(clicked()), mPartner4, SLOT(showMaximized()));
}

SecondWindow::Rating::Rating(QWidget *parent)
    : QWidget(parent), rating_value(100) {}

void SecondWindow::Rating::paintEvent(QPaintEvent* e) {
    QPainter painter(this);
    painter.setBrush(QBrush(QColor::fromRgb(0,150,0)));
    painter.setPen(QColor::fromRgb(0,150,0));
    // Changes color of rating bar as rating_value decreases
    if (rating_value <= 75) {
        painter.setBrush(QBrush(QColor::fromRgb(135,199,4)));
        painter.setPen(QColor::fromRgb(135,199,4));
    } if (rating_value <= 50) {
        painter.setBrush(QBrush(QColor::fromRgb(247,187,0)));
        painter.setPen(QColor::fromRgb(247,187,0));
    } if (rating_value <= 25) {
        painter.setBrush(QBrush(QColor::fromRgb(233,75,26)));
        painter.setPen(QColor::fromRgb(233,75,26));
    } if (rating_value <= 10) {
        painter.setBrush(QBrush(QColor::fromRgb(199,0,0)));
        painter.setPen(QColor::fromRgb(199,0,0));
    }
    QRectF pff(0,15,rating_value,15);
    painter.drawRect(pff);
    return;
}

void SecondWindow::Rating::change_rating_bar(int a){
    rating_value = rating_value - a;
    update();
}

void SecondWindow::Rating::reset_rating(){
    rating_value = 100;
}
