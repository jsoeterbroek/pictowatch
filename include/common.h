#include <ArduinoJson.h>
#include <colors.h>

#define PD_VERSION_MAJOR 1
#define PD_VERSION_MINOR 3
#define PD_VERSION_PATCH 1

static inline int pd_version_major(void) {
  return PD_VERSION_MAJOR;
}
static inline int pd_version_minor(void) {
  return PD_VERSION_MINOR;
}
static inline int pd_version_patch(void) {
  return PD_VERSION_PATCH;
}

// status flags
boolean STATUS_WIFI_OK = false;
boolean STATUS_WIFI_MGR_OK = false;
boolean STATUS_WIFI_MGR_CONFIG_MODE_OK = false;
boolean STATUS_TIME_OK = false;
boolean STATUS_NTP_OK = false;
boolean STATUS_CONFIG_DATA_OK = false;
boolean STATUS_BLE_OK = false;
boolean STATUS_GET_CONFIG_DATA_FS_OK = false;
boolean STATUS_SET_CONFIG_DATA_FS_OK = false;
boolean STATUS_GET_CONFIG_DATA_HTTP_OK = false;

boolean GET_CONFIG_DATA_HTTP = false;
boolean GET_CONFIG_DATA_SPIFF = true;

const char *ntpServer = "europe.pool.ntp.org";
#define NTP_TIMEZONE "UTC+1"
String timezone = "CET-1CEST,M3.5.0,M10.5.0/3";

// WiFi
const char *wifi_mngr_networkname = "pictostick";
const char *wifi_mngr_password = "password";

// FIXME: servername for HTTP server needs to change
String serverName = "http://192.168.178.148:8001";

#define FORMAT_SPIFFS_IF_FAILED true

// configuration file in json format stored in SPIFFS fs
const char *cfilename = "/data.json";

// store values from JSON config file
const char *config_comment;       // nullptr
const char *config_version;       // "1.0.1"
const char *config_name;          // "Peter"
const char *config_device_ip;     // "128.8.2.123"
const char *config_date_created;  // "24-03-2025"
const char *config_date_valid;    // "23-03-2025"
int8_t config_activities_size = 0;
int config_activities_size_max = 19;  // hardcoded maximum of activities still able to show mini menu
int current_activity_index = 0;
int ps_current_activity_index = 0;

// box for picto 100 x 100 pixels
int16_t picto_box_width = 144;
int16_t picto_box_height = 144;
#define MAX_IMAGE_WIDTH 140  // Adjust for your images
int16_t xpos = 50;
int16_t ypos = 50;

//time variables
String h, m, s;
int day, month;
int8_t hour = 0;
int8_t minute = 0;
int8_t second = 0;

//battery
int vol;
int volE;

//sleep variables
int sleepTime = 60;
int ts, tts = 0;
bool slp = false;

#define BUTTON_PRESSED  LOW
#define BUTTON_RELEASED HIGH

String lang = "en";  // "en" for english, "nl" for dutch
bool marked_done = false;

int cursor = 0;
