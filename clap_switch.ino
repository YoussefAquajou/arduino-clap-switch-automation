// ---------------------------------------------------------------------------
// Project: Acoustic Automation Switch (Double Clap Detector)
// Description: Uses a KY-038 sound sensor to detect a double-clap pattern
//              and toggle an output state (LED/Relay) while filtering noise.
// ---------------------------------------------------------------------------

const int sensor = 2; // Pin du capteur de son KY-038 [cite: 384, 385, 464]
const int led = 13;   // Pin de la LED (ou Relais) [cite: 387, 388, 465]

// Paramètres de configuration (Timing)
const unsigned long maxInterval = 500; // Intervalle max entre les claquements en ms [cite: 390, 467, 468]
const unsigned long debounceDelay = 50; // Délai anti-rebond pour filtrer le bruit en ms [cite: 392, 469]

// Variables d'état
unsigned long lastClapTime = 0; [cite: 394]
bool ledState = false; [cite: 395]

void setup() {
    pinMode(sensor, INPUT); [cite: 400]
    pinMode(led, OUTPUT); [cite: 402]
    Serial.begin(9600); // Initialisation du moniteur série pour le débogage [cite: 404, 479]
}

void loop() {
    static bool clapDetected = false; [cite: 410]
    int sensorValue = digitalRead(sensor); [cite: 413]

    // Si un son dépasse le seuil du capteur
    if (sensorValue == HIGH) { [cite: 416]
        unsigned long currentTime = millis(); [cite: 418]

        // Logiciel Anti-rebond (filtre les échos et faux positifs)
        if (currentTime - lastClapTime > debounceDelay) { [cite: 429, 430]
            
            // Premier clap détecté
            if (!clapDetected) { [cite: 431]
                clapDetected = true; [cite: 432]
                lastClapTime = currentTime; [cite: 433]
            } 
            // Deuxième clap détecté
            else { [cite: 434]
                // Vérifie si le second clap est dans l'intervalle temporel autorisé
                if (currentTime - lastClapTime <= maxInterval) { [cite: 435, 436]
                    ledState = !ledState; // Inverse l'état de la LED [cite: 437]
                    digitalWrite(led, ledState); [cite: 439]
                    Serial.println("Double Clap Detected!"); [cite: 441]
                    clapDetected = false; // Réinitialise le détecteur [cite: 443]
                }
                lastClapTime = currentTime; [cite: 447]
            }
        }
    }

    // Réinitialisation si le temps d'attente pour le second clap est dépassé
    if (millis() - lastClapTime > maxInterval) { [cite: 455]
        clapDetected = false; [cite: 457]
    }
}