#include "eloquent.h"
#include "eloquent/networking/wifi.h"
#include "eloquent/vision/camera/esp32/webserver.h"
#include "eloquent/vision/camera/aithinker.h"
void setup() {
    Serial.begin(115200);
    delay(2000);
    camera.jpeg();
    camera.qqvga();
    while (!wifi.connectTo("SHIELD", "AVENGERS"))
        Serial.println("Cannot connect to WiFi");
    while (!camera.begin())
        Serial.println("Cannot connect to camera");
    webServer.start();
    Serial.print("Camera web server started at http://"/);
    Serial.println(WiFi.localIP());
}
void loop() {
    // do nothing
}