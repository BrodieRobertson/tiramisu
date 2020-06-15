#include <stdio.h>

#include "config.h"
#include "format.h"

/* I'm not a C programmer, there's a probably a better way to do this */
const char *APP_NAME_NAME = "APP_NAME:";
const char *APP_ICON_NAME = "APP_ICON:";
const char *REPLACES_ID_NAME = "REPLACES_ID:";
const char *TIMEOUT_NAME = "TIMEOUT:";
const char *SUMMARY_NAME = "SUMMARY:";
const char *BODY_NAME = "BODY:";

void output_notification(gchar *app_name, guint32 replaces_id, gchar *app_icon,
    gchar *summary, gchar *body, GVariant *actions, GVariant *hints,
    gint32 timeout) {
    /* This function will raise warnings. I don't fucking care. */

    /* 2048 characters should be significantly long enough*/
    char *string = (char *)calloc(2048, sizeof(char));

    strcat(string, APP_NAME_NAME);
		strcat(string, app_name);

#ifdef RECEIVE_APP_ICON
    sprintf(string, "%s%s%s%s", string, OUTPUT_DELIMITER, APP_ICON_NAME, app_icon);
#endif

    /* TODO: actions */
    /* TODO: hints */

#ifdef RECEIVE_REPLACES_ID
    sprintf(string, "%s%s%s%lu", string, OUTPUT_DELIMITER, REPLACES_ID_NAME, replaces_id);
#endif

    sprintf(string, "%s%s%s%d%s%s%s%s%s%s", string, OUTPUT_DELIMITER, TIMEOUT_NAME, timeout,
				OUTPUT_DELIMITER, SUMMARY_NAME, summary, OUTPUT_DELIMITER, BODY_NAME, body);

    printf("%s\n", string);
    fflush(stdout);

    free(string);
}
