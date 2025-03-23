/*
 * 🚨 WARNING: CHALLENGE MODE ACTIVATED 🚨
 * 
 * 1️⃣ Sit back, take a deep breath, and **THINK**.
 * 2️⃣ For the next **10 minutes**, avoid using **Gen AI, ChatGPT, or any shortcuts**.
 * 3️⃣ Trust your **brain**—you’re smarter than you think!
 * 4️⃣ Consider yourself a **LOSER** if you cheat. Seriously, promise yourself you won't. 😤
 * 5️⃣ If you solve it on your own, **you WIN** and level up as a true programmer and come and meet me ! 
 * 
 * 
 * 💡 Remember: The best coders aren’t the ones who copy-paste. They are the ones who **struggle, think, fail, and then succeed.** 
 *    
 * Now, write your code! You got this! 💪🔥
 */

 #include <stdio.h>

 #define MAX_ROOMS 5  //  max number of rooms
 
 // Function prototypes
void initializeSystem(int light[], int temperature[], int motion[], int security[]);
void displayMenu();
void controlLights(int light[]);
void readTemperature(int temperature[]);
void detectMotion(int motion[]);
void securitySystem(int security[]);
void analyzeHouseStatus(int light[], int temperature[], int motion[], int security[]);

int main() {
    int light[MAX_ROOMS], temperature[MAX_ROOMS], motion[MAX_ROOMS], security[MAX_ROOMS];
    int choice;
    
    // Initialize system
    initializeSystem(light, temperature, motion, security);
    printf("\nInitializing system...\n");
    
    while(1){

    
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                controlLights(light);
                break;
            case 2:
                readTemperature(temperature);
                break;
            case 3:
                detectMotion(motion);
                break;
            case 4:
                securitySystem(security);
                break;
            case 5:
                analyzeHouseStatus(light, temperature, motion, security);
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    
    }
    return 0;
}

void initializeSystem(int light[], int temperature[], int motion[], int security[]) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        light[i] = 0;
        temperature[i] = 22;
        motion[i] = 0;
        security[i] = 1;
    }
}

void displayMenu() {
    printf("\n===== Smart Home Menu =====\n");
    printf("1. Toggle Light\n");
    printf("2. Read Temperature\n");
    printf("3. Check Motion Sensor\n");
    printf("4. Lock/Unlock Security System\n");
    printf("5. House Status Summary\n");
    printf("6. Exit\n");
}

void controlLights(int light[]) {
    int room;
    printf("Enter room number to toggle light (1-%d): ", MAX_ROOMS);
    scanf("%d", &room);
    if (room >= 1 && room <= MAX_ROOMS) {
        light[room - 1] = !light[room - 1];
        printf("Light in Room %d is now %s.\n", room, light[room - 1] ? "ON" : "OFF");
    } else {
        printf("Invalid room number.\n");
    }
}

void readTemperature(int temperature[]) {
    int room;
    printf("Enter room number to read temperature (1-%d): ", MAX_ROOMS);
    scanf("%d", &room);
    if (room >= 1 && room <= MAX_ROOMS) {
        printf("Temperature in Room %d: %d°C\n", room, temperature[room - 1]);
    } else {
        printf("Invalid room number.\n");
    }
}

void detectMotion(int motion[]) {
    int room;
    printf("Enter room number to check motion (1-%d): ", MAX_ROOMS);
    scanf("%d", &room);
    if (room >= 1 && room <= MAX_ROOMS) {
        printf("%s detected in Room %d.\n", motion[room - 1] ? "Motion" : "No motion", room);
    } else {
        printf("Invalid room number.\n");
    }
}

void securitySystem(int security[]) {
    int room;
    printf("Enter room number to toggle security (1-%d): ", MAX_ROOMS);
    scanf("%d", &room);
    if (room >= 1 && room <= MAX_ROOMS) {
        security[room - 1] = !security[room - 1];
        printf("Security Lock in Room %d is now %s.\n", room, security[room - 1] ? "LOCKED" : "UNLOCKED");
    } else {
        printf("Invalid room number.\n");
    }
}

void analyzeHouseStatus(int light[], int temperature[], int motion[], int security[]) {
    printf("\nHouse Status:\n");
    for (int i = 0; i < MAX_ROOMS; i++) {
        printf("Room %d: Light %s, Temp %d°C, %s Motion, %s\n", 
               i + 1, 
               light[i] ? "ON" : "OFF", 
               temperature[i], 
               motion[i] ? "Detected" : "No", 
               security[i] ? "Locked" : "Unlocked");
    }
}
