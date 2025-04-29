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

enum GameState {
    MAIN_MENU, PLAY, DOG_BREEDS, CAT_BREEDS, GOLDEN_RETRIEVER, BULLDOG, 
    POODLE, BICHON, SIAMESE, SFINX, PERSIAN, PROCESS
};

int Game::dogCount = 0;
int Game::catCount = 0;

int main() {
     
	Dog dog = dog.createDogSafe("", 3, "Large");
    Game game;
        
    Bichon b = dog.createDogSafe("Bella", 2, "Bichon");
	Bichon b1 = dog.createDogSafe("Luna", -1, "Bichon");
    Poodle pud1 = dog.createDogSafe("Olive", 4, "Poodle");
    Poodle pud = dog.createDogSafe("Gracie", 2, "Poodle", { "Cute" });
	Bulldog bulldog = dog.createDogSafe("Max", 3, "Bulldog");
	GoldenRetriever golden = dog.createDogSafe("Rex", 5, "Golden Retriever");

    Cat cat = cat.createCatSafe("Felix", 1);
	Cat cat1 = cat.createCatSafe("Mittens", 2);
    Siamese s = cat.createCatSafe("Tom", 3);
	Sfinx sfinx = cat.createCatSafe("Jerry", 2, { "Curious" });
	Sfinx sfinx2 = cat.createCatSafe("Mittens", 4);
	Persian pers = cat.createCatSafe("Whiskers",  1);
    
    try { 
        game.addAnimal(&b);
		game.addAnimal(&b1);
        game.addAnimal(&pud1);
        game.addAnimal(&pud);
        game.addAnimal(&bulldog);
        game.addAnimal(&golden);
        game.addAnimal(&cat1);
        game.addAnimal(&s);
        game.addAnimal(&sfinx);
        game.addAnimal(&sfinx2);
        game.addAnimal(&pers);
    }
	catch (const std::invalid_argument& e) {
		std::cerr << "Error adding animal: " << e.what() << std::endl;
	}    

    
    GameState currentState = MAIN_MENU;

    InitWindow(800, 800, "Adopt an animal");
	SetTargetFPS(60);
	Button dogButton("Dog", 190, 250, 70, 50);
	Button catButton("Cat", 300, 250, 70, 50);

	std::string processName;
    Animal* processAnimal = nullptr;

    Vector2 playerPos = { 50, 750 };  
    float playerSpeed = 2.0f;

    Rectangle goal = { 700, 50, 40, 40 };

    Rectangle obstacle1 = { 400, 300, 30, 30 };
	Rectangle obstacle2 = { 500, 200, 30, 30 };
	Rectangle obstacle3 = { 100, 400, 30, 30 };
	Rectangle obstacle4 = { 200, 200, 30, 30 };
    Rectangle obstacle5 = { 400, 600, 30, 30 };



    float timeLimit = 15.0f;    
    float timeLeft = timeLimit;
    bool gameOver = false;
    bool playerWon = false;


    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        switch (currentState) {
            case MAIN_MENU:
                DrawText("Pick an animal", 190, 200, 20, PURPLE);
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
                DrawText("Dog breeds", 190, 100, 20, PURPLE);
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
                DrawText("Cat breeds", 190, 100, 20, PURPLE);
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
					processName = processAnimal->getName();
					game.displayAnimalSound(processAnimal);
				}
				
                try {
                    char* text = new char[processName.length() + 24];
                    strcpy(text, "You are playing with ");
                    strcat(text, processName.c_str());
                    DrawText(text, 190, 200, 20, PURPLE);
                    delete []text;
                }
                catch (std::exception& e) {
					std::cout << "Error: " << e.what() << std::endl;
                }
                Button playButton("Play", 250, 400, 90, 50);
                playButton.Draw();
                if (playButton.isPressed()) {
                    currentState = PLAY;
                }
				
                break;
            }

            case PLAY: {
                ClearBackground(RAYWHITE);

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

					// se verifica daca a ajuns la tinta
                    Rectangle playerRec = { playerPos.x, playerPos.y, 40, 40 };
                    if (CheckCollisionRecs(playerRec, goal)) {
                        gameOver = true;
                        playerWon = true;
                    }

					// obstacole
                    if (CheckCollisionRecs(playerRec, obstacle1) || 
                        CheckCollisionRecs(playerRec, obstacle2) ||
                        CheckCollisionRecs(playerRec, obstacle3) ||
                        CheckCollisionRecs(playerRec, obstacle4) ||
                        CheckCollisionRecs(playerRec, obstacle5) ){
                        gameOver = true;
                        playerWon = false;
                    }
                }

                DrawRectangleV(playerPos, { 40, 40 }, BLUE);
                DrawRectangleRec(goal, GREEN);
				DrawRectangleRec(obstacle1, RED);
				DrawRectangleRec(obstacle2, RED);
				DrawRectangleRec(obstacle3, RED);
				DrawRectangleRec(obstacle4, RED);
				DrawRectangleRec(obstacle5, RED);


                // timer
                DrawText(TextFormat("Time: %.2f", timeLeft), 600, 20, 20, BLACK);

                if (gameOver) {
                    if (playerWon) {
						char* text = new char[processName.length() + 19];
                        strcpy(text, "You can adopt ");
						if (processAnimal) {
							processAnimal->setAdopted();
                            strcat(text, processAnimal->getName().c_str());
						}
						
                        DrawText(text, 300, 400, 30, DARKGREEN);
                        delete[]text;
                    }
                    else {
                        char* text = new char[processName.length() + 19];
                        strcpy(text, "You can't adopt ");
                        strcat(text, processName.c_str());
                        DrawText(text, 300, 400, 30, RED);
						delete[]text;
                    }
                }

                break;
            }

		}
		
        EndDrawing();
    }

	CloseWindow();

    return 0;
}



