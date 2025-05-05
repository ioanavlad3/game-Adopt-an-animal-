#include "dog.h"
#include "cat.h"
#include "bichon.h"
#include "Poodle.h"
#include "Bulldog.h"
#include "game.h"
#include "button.h"
#include "Golden_Retriever.h"
#include "siamese.h"
#include "Sfinx.h"
#include "Persian.h"
#include "raylib.h"
#include <iostream>
#include <exception>
#include <stdexcept> 
#include <ctime>
#define MAX_LENGTH_NAME 15 

enum GameState {
    NAME, MAIN_MENU, PLAY, DOG_BREEDS, CAT_BREEDS, GOLDEN_RETRIEVER, BULLDOG, 
    POODLE, BICHON, SIAMESE, SFINX, PERSIAN, PROCESS
};

struct NamedTexture {
    std::string name;     
    Texture2D texture;   
};

int Game::dogCount = 0;
int Game::catCount = 0;

std::vector<NamedTexture> images;

static void fillImages() {
    images.push_back({ "Bichon", LoadTexture("Bichon.png") });
    images.push_back({ "Bichon2", LoadTexture("Bichon2.png") });
    images.push_back({ "Poodle", LoadTexture("Poodle.png") });
    images.push_back({ "Poodle2", LoadTexture("Poodle2.png") });
    images.push_back({ "Golden Retriever", LoadTexture("Golden Retriever.png") });
    images.push_back({ "Golden Retriever2", LoadTexture("Golden Retriever2.png") });
    images.push_back({ "Bulldog", LoadTexture("Bulldog.png") });
    images.push_back({ "Bulldog2", LoadTexture("Bulldog2.png") });
    images.push_back({ "Sfinx", LoadTexture("Sfinx.png") });
    images.push_back({ "Sfinx2", LoadTexture("Sfinx2.png") });
    images.push_back({ "Persian", LoadTexture("Persian.png") });
    images.push_back({ "Persian2", LoadTexture("Persian2.png") });
    images.push_back({ "Siamese", LoadTexture("Siamese.png") });
    images.push_back({ "Siamese2", LoadTexture("Siamese2.png") });
}

static int cntHeart = 3;

static void displayHearts(int numberH, Texture2D img) {
    int x = 50;
    int y = 20;
    for (int i = 0; i < numberH; i++) {
        DrawTexture(img, x, y, WHITE);
        x += 60;
    }
}

int main() {
    std::srand(std::time(nullptr));

	Dog dog = dog.createDogSafe("", 3, "Bichon");
    Dog d1 = dog.createDogSafe("Buna", 1, "Labrador");
    Game game;
        
    Bichon b = dog.createDogSafe("Bella", 2, "Bichon");
	Bichon b1 = dog.createDogSafe("Luna", -1, "Bichon");
    Bichon b2 = dog.createDogSafe("Pluto", 3, "Bichon");
    Poodle pud1 = dog.createDogSafe("Olive", 4, "Poodle");
    Poodle pud = dog.createDogSafe("Gracie", 2, "Poodle", { "Cute" });
    Poodle p2 = dog.createDogSafe("Charlie", 1, "Poodle");
	Bulldog bulldog = dog.createDogSafe("Max", 3, "Bulldog");
    Bulldog bull1 = dog.createDogSafe("Rocky", 4, "Bulldog");
	GoldenRetriever golden = dog.createDogSafe("Rex", 5, "Golden Retriever");
    GoldenRetriever g1 = dog.createDogSafe("Milo", 3, "Golden Retriever");
    

    Cat cat = cat.createCatSafe("Felix", 1);
	Cat cat1 = cat.createCatSafe("Mittens", 2);
    Siamese s = cat.createCatSafe("Tom", 3);
    Siamese s2 = cat.createCatSafe("Leo", 1, { "Adventurous" });
    Siamese s3 = cat.createCatSafe("Bella", 2);
	Sfinx sfinx = cat.createCatSafe("Jerry", 2, { "Curious" });
	Sfinx sfinx2 = cat.createCatSafe("Mittens", 4);
	Persian pers = cat.createCatSafe("Whiskers",  1);
    
    try { 
        game.addAnimal(&dog);
        game.addAnimal(&d1);
        game.addAnimal(&b);
		game.addAnimal(&b1);
        game.addAnimal(&b2);
        game.addAnimal(&pud1);
        game.addAnimal(&pud);
        game.addAnimal(&p2);
        game.addAnimal(&bulldog);
        game.addAnimal(&bull1);
        game.addAnimal(&golden);
        game.addAnimal(&g1);
        game.addAnimal(&cat1);
        game.addAnimal(&s);
        game.addAnimal(&s2);
        game.addAnimal(&s3);
        game.addAnimal(&sfinx);
        game.addAnimal(&sfinx2);
        game.addAnimal(&pers);
    }
	catch (const std::invalid_argument& e) {
		std::cerr << "Error adding animal: " << e.what() << std::endl;
	}      
   
    GameState currentState = NAME;

    InitWindow(1600, 800, "Adopt an animal");
	SetTargetFPS(60);
    BeginBlendMode(BLEND_ALPHA);

    //imagini pentru joc
    Texture2D background = LoadTexture("fundal_inceput.jpg");
    if (background.width == 0 || background.height == 0) {
        std::cout << "Failed to load background texture!\n";
    }
    Texture2D girl = LoadTexture("girl.png");
    Texture2D boy = LoadTexture("boy.png");
    Texture2D treasure = LoadTexture("treasure2.png");
    Texture2D openTreasure = LoadTexture("open_treasure.png");
    Texture2D heart = LoadTexture("heart.png");
    Texture2D sadFace = LoadTexture("sadFace.png");

    fillImages();


	Button dogButton("Dog", 700, 350, 70, 50);
	Button catButton("Cat", 850, 350, 70, 50);

	std::string processName;
    Animal* processAnimal = nullptr;

    Vector2 playerPos = { 750, 380 };  
    float playerSpeed = 3.0f;

    Rectangle goal1 = { 50, 650, 70, 70 };
    Rectangle goal2 = { 1420, 650, 70, 70 };
    Rectangle goal3 = { 1420, 50, 70, 70 };
    Rectangle goal4 = { 50, 50, 70, 70 };

    Rectangle goals[] = { goal1, goal2, goal3, goal4 };

    Rectangle finish;

    float timeLimit = 30.0f;    
    float timeLeft = timeLimit;
    bool gameOver = false;
    bool playerWon = false;
    bool addCoins = false;
    std::string savePlayerName;
    std::string gender;


    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(background, 0, 0, WHITE);

        switch (currentState) {
            case NAME: {
                DrawText("Insert your name: ", 600, 200, 50, BLACK);

                static std::string playerName = "";
                static bool textBoxActive = false;
                Rectangle textBox = { 600, 300, 400, 50 };

                //desenez casuta
                DrawRectangleLines(textBox.x, textBox.y, textBox.width, textBox.height, BLACK);
                DrawText(playerName.c_str(), textBox.x + 5, textBox.y + 15, 30, BLACK);

                // detecteaza daca mouse-ul atinge casuta
                if (CheckCollisionPointRec(GetMousePosition(), textBox)) {
                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                        textBoxActive = true;
                    }
                }
                else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    textBoxActive = false;
                }

                // daca e activat, retine ce se scrie
                if (textBoxActive) {
                    int key = GetCharPressed();
                    while (key > 0) {
                        if ((key >= 32) && (key <= 125)) {
                            if (playerName.length() < MAX_LENGTH_NAME) {  
                                playerName += (char)key;
                            }
                        }
                        key = GetCharPressed();
                    }

                    // Backspace
                    if (IsKeyPressed(KEY_BACKSPACE) && !playerName.empty()) {
                        playerName.pop_back();
                    }
                }

                
                Button next("Next", 600, 400, 70, 40);
                next.Draw();
                if (next.isPressed()) {
                    savePlayerName = playerName;  
                    playerName = "";           // resetare
                    currentState = MAIN_MENU;
                }
                gender = game.boyOrGirl(savePlayerName);
                break;
            }

            case MAIN_MENU:
                DrawText("Pick an animal", 650, 200, 50, BLACK);
                dogButton.Draw();
                catButton.Draw();

                if (dogButton.isPressed()) {
                    currentState = DOG_BREEDS;
                }
                else if (catButton.isPressed()) {
                    currentState = CAT_BREEDS;
                }
                break;

            case DOG_BREEDS: {
                DrawText("Dog breeds", 700, 200, 30, BLACK);
                game.displayDogsSpecies();

                Button backButton("Back", 50, 700, 70, 40);
                backButton.Draw();
                if (backButton.isPressed()) {
                    currentState = MAIN_MENU;
                }

                for (auto& btn : game.getDogBreedButtons()) {
                    if (btn.isPressed()) {
                        if (btn.getText() == "Golden Retriever") {
                            currentState = GOLDEN_RETRIEVER;
                        }
                        else if (btn.getText() == "Bulldog") {
                            currentState = BULLDOG;
                        }
                        else if (btn.getText() == "Poodle") {
                            currentState = POODLE;
                        }
                        else if (btn.getText() == "Bichon") {
                            currentState = BICHON;
                        }
                    }
                }
                break;
            }
        
            case CAT_BREEDS: {
                DrawText("Cat breeds", 700, 200, 30, BLACK);
                game.displayCatsSpecies();
                Button backButton("Back", 50, 700, 70, 40);
                backButton.Draw();
                if (backButton.isPressed()) {
                    currentState = MAIN_MENU;
                }

                for (auto& btn : game.getCatBreedButtons()) {
                    if (btn.isPressed()) {
                        if (btn.getText() == "Siamese") {
                            currentState = SIAMESE;
                        }
                        else if (btn.getText() == "Sfinx") {
                            currentState = SFINX;
                        }
                        else if (btn.getText() == "Persian") {
                            currentState = PERSIAN;
                        }
                    }
                }
                break;
            }

            case SIAMESE: {
                Animal* sCat = game.displayAnimalSpecies("Siamese");
                Siamese* selectedCat = dynamic_cast<Siamese*>(sCat);

                if (selectedCat) {
                    currentState = PROCESS;
                    processAnimal = selectedCat;
                }
                Button backButton("Back", 50, 700, 70, 40);
                backButton.Draw();
                if (backButton.isPressed()) {
                    currentState = CAT_BREEDS;
                }
                break;
            }
		
            case SFINX: {
                Animal* sCat = game.displayAnimalSpecies("Sfinx");
                Sfinx* selectedCat = dynamic_cast<Sfinx*>(sCat);

                if (selectedCat) {
                    currentState = PROCESS;
                    processAnimal = selectedCat;
                }
                Button backButton("Back", 50, 700, 70, 40);
                backButton.Draw();
                if (backButton.isPressed()) {
                    currentState = CAT_BREEDS;
                }
                break;
            }

            case PERSIAN: {
                Animal* sCat = game.displayAnimalSpecies("Persian");
                Persian* selectedCat = dynamic_cast<Persian*>(sCat);

                if (selectedCat) {
                    currentState = PROCESS;
                    processAnimal = selectedCat;
                }
                Button backButton("Back", 50, 700, 70, 40);
                backButton.Draw();
                if (backButton.isPressed()) {
                    currentState = CAT_BREEDS;
                }
                break;
            }

            case GOLDEN_RETRIEVER: {
                Animal* sDog = game.displayAnimalSpecies("Golden Retriever");
                GoldenRetriever* selectedDog = dynamic_cast<GoldenRetriever*>(sDog);

                if (selectedDog != nullptr) {
                    currentState = PROCESS;
                    processAnimal = selectedDog;
                }
                Button backButton("Back", 50, 700, 70, 40);
                backButton.Draw();
                if (backButton.isPressed()) {
                    currentState = DOG_BREEDS;
                }
            
                break;
            }
        
            case BULLDOG: {
                Animal* sDog = game.displayAnimalSpecies("Bulldog");
                Bulldog* selectedDog = dynamic_cast<Bulldog*>(sDog);

                if (selectedDog) {
                    currentState = PROCESS;
                    processAnimal = selectedDog;
                }
                Button backButton("Back", 50, 700, 70, 40);
                backButton.Draw();
                if (backButton.isPressed()) {
                    currentState = DOG_BREEDS;
                }
                break;
            }
        
            case POODLE: {
                Animal* sDog = game.displayAnimalSpecies("Poodle");
                Poodle* selectedAnimal = dynamic_cast<Poodle*>(sDog);

                if (selectedAnimal) {
                    currentState = PROCESS;
                    processAnimal = selectedAnimal;
                }
                Button backButton("Back", 50, 700, 70, 40);
                backButton.Draw();
                if (backButton.isPressed()) {
                    currentState = DOG_BREEDS;
                }
                break;
            }
      
            case BICHON: {
                Animal* sDog = game.displayAnimalSpecies("Bichon");
                Bichon* selectedAnimal = dynamic_cast<Bichon*>(sDog);

                if (selectedAnimal) {
                    currentState = PROCESS;
                    processAnimal = selectedAnimal;
                }

                Button backButton("Back", 50, 700, 70, 40);
                backButton.Draw();
                if (backButton.isPressed()) {
                    currentState = DOG_BREEDS;
                }
                break;
            }

            case PROCESS: {
				if (processAnimal) {
                    // daca un animal a fost ales, se seteaza ca adoptat
                    processAnimal->setAdopted();
					processName = processAnimal->getName();
					game.displayAnimalSound(processAnimal);
                    std::string image = processAnimal->getSpecies();
                    
                    for (const auto& i : images) {
                        if (i.name == image) {
                            DrawTexture(i.texture, 400, 100, WHITE);
                            break;
                        }
                    }
				}
				
                try {
                    char* text = new char[processName.length() + 24];
                    strcpy(text, "You are playing with ");
                    strcat(text, processName.c_str());
                    DrawText(text, 600, 50, 50, BLACK);
                    delete []text;
                }
                catch (std::exception& e) {
					std::cout << "Error: " << e.what() << std::endl;
                }
                
                if (cntHeart >= 1) {
                    Button playButton("Play", 250, 400, 90, 50);
                    playButton.Draw();
                    if (playButton.isPressed()) {
                        currentState = PLAY;
                        int final = game.randomNumber(1, 4);
                        finish = goals[final - 1];
                        
                    }
                }
                else {
                    DrawText("You don't have enough lives to play!", 150, 400, 20, RED);
                    DrawTexture(sadFace, 300, 450, WHITE);
                }
                                

                int coins = game.getCoins();
                std::string text = "Coins: " + std::to_string(coins);
                DrawText(text.c_str(), 50, 30, 35, BLACK);
                
				
                break;
            }

            case PLAY: {
                ClearBackground(RAYWHITE);

                Vector2 oldPos = playerPos;
                displayHearts(cntHeart, heart);
                
                if (game.isEmptyObstacles()) {
                    game.generateObstacles(playerPos, 40.0f, 50.0f);
                }

                if (!gameOver) {
                    if (IsKeyDown(KEY_RIGHT)) playerPos.x += playerSpeed;
                    if (IsKeyDown(KEY_LEFT))  playerPos.x -= playerSpeed;
                    if (IsKeyDown(KEY_UP))    playerPos.y -= playerSpeed;
                    if (IsKeyDown(KEY_DOWN))  playerPos.y += playerSpeed;

                    // Update timer
                    timeLeft -= GetFrameTime();
                    if (timeLeft <= 0.0f) {
                        timeLeft = 0.0f;
                        gameOver = true;
                        playerWon = false;
                    }

                    Rectangle playerRec = { playerPos.x + 20, playerPos.y + 10, 
                        40, 50};


                    if (CheckCollisionRecs(playerRec, finish)) {
                        gameOver = true;
                        playerWon = true;
                    }
                    else {
                        game.updateObstacles(goals);
                    }

					// obstacole
                    if ( game.checkColl(playerRec) ){
                        gameOver = true;
                        playerWon = false;
                    }

                    // evitarea atingerii altor obstacole
                    for (int i = 0; i < 4; i++) {
                        Rectangle g = goals[i];

                        if (g.x == finish.x && g.y == finish.y) {
                            continue;
                        }

                        if (CheckCollisionRecs(playerRec, g)) {
                            playerPos = oldPos;
                            break;
                        }
                    }

                    if (playerPos.x + 60 >= 1600 || playerPos.x + 25 <= 0 ||
                        playerPos.y + 90 >= 800 || playerPos.y + 10 <= 0) {
                        playerPos = oldPos;
                    }
                }
                if (gender == "girl") {
                    DrawTextureV(girl, playerPos, WHITE);
                }
                else {
                    DrawTextureV(boy, playerPos, WHITE);
                }
                
                DrawTexture(treasure, goal1.x, goal1.y, WHITE);
                DrawTexture(treasure, goal2.x, goal2.y, WHITE);
                DrawTexture(treasure, goal3.x, goal3.y, WHITE);
                DrawTexture(treasure, goal4.x, goal4.y, WHITE);
				
               
                game.displayRandomObstacles();
           
                // timer
                DrawText(TextFormat("Time: %.2f", timeLeft), 1400, 20, 20, BLACK);

                if (gameOver) {
                    Button Back("Back", 750, 400, 90, 50);
                    Back.Draw();
                    if (Back.isPressed()) {
                        currentState = PROCESS;
                        if (!playerWon) {
                            cntHeart -= 1;
                        }
                        gameOver = false;
                        playerWon = false;
                        playerPos = { 750, 380 };
                        timeLeft = timeLimit;
                        game.clearObstacles();
                        addCoins = false;
                    }
                    

                    if (playerWon) {
                        if (!addCoins) {
                            game.addCoins(200);
                            addCoins = true;
                        }

                        DrawTexture(openTreasure, finish.x, finish.y, WHITE);
                        std::string image = processAnimal->getSpecies() + "2";

                        for (const auto& i : images) {
                            if (i.name == image) {
                                DrawTexture(i.texture, finish.x + 20, finish.y, WHITE);
                                break;
                            }
                        }

						char* text = new char[processName.length() + 19];
                        strcpy(text, "You saved ");
						if (processAnimal) {
							processAnimal->setAdopted();
                            strcat(text, processAnimal->getName().c_str());
						}
						
                        DrawText(text, 700, 300, 50, DARKGREEN);
                        delete[]text;

                        Button replay("Replay", 850, 400, 90, 50);
                        replay.Draw();
                        if (replay.isPressed()) {
                            currentState = PLAY;
                            gameOver = false;
                            playerWon = false;
                            playerPos = { 750, 380 };
                            timeLeft = timeLimit;
                            game.clearObstacles();
                            int final = game.randomNumber(1, 4);
                            finish = goals[final - 1];
                            addCoins = false;
                        }                        

                    }
                    else {
                        char* text = new char[processName.length() + 19];
                        strcpy(text, "You didn't save ");
                        strcat(text, processName.c_str());
                        DrawText(text, 650, 300, 50, RED);
						delete[]text;
                        
                        if (cntHeart > 1) {
                            Button replay("Replay", 850, 400, 90, 50);
                            replay.Draw();
                            if (replay.isPressed()) {
                                currentState = PLAY;
                                gameOver = false;
                                playerWon = false;
                                playerPos = { 750, 380 };
                                timeLeft = timeLimit;
                                game.clearObstacles();
                                int final = game.randomNumber(1, 4);
                                finish = goals[final - 1];
                                cntHeart -= 1;
                            }
                        }
                        else if (cntHeart == 1 && game.getCoins() >= 100 ) {
                            Button buy("Buy 1 heart for 100 coins", 850, 400, 320, 50);
                            buy.Draw();
                            if (buy.isPressed()) {
                                game.addCoins(-100);
                                currentState = PLAY;
                                gameOver = false;
                                playerWon = false;
                                playerPos = { 750, 380 };
                                timeLeft = timeLimit;
                                game.clearObstacles();
                                int final = game.randomNumber(1, 4);
                                finish = goals[final - 1];
                            }
                        }
                        
                    }
                }
                break;
            }

		}
		
        EndDrawing();
    }
    UnloadTexture(background);
    UnloadTexture(girl);
    UnloadTexture(boy);
    UnloadTexture(treasure);
    for (auto& i : images) {
        UnloadTexture(i.texture);
    }
    UnloadTexture(sadFace);

	CloseWindow();

    return 0;
}



