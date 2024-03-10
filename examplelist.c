/* This file is not used for the standalone project - only by LVGL CI. */
#include <stddef.h>
#include <stdio.h>
#include "lvgl/lvgl.h"
#include "examplelist.h"
#include <emscripten.h>

extern lv_font_t NotoSansKR_Regular_28;

const struct lv_ci_example  lv_ci_example_list[] = {
  { "hello", lv_example_get_started_1 },
  {NULL, NULL}  
};

#if 1
EM_JS(int, canvas_get_width, (), {
  return canvas.width;
});

EM_JS(int, canvas_get_height, (), {
  return canvas.height;
});
#endif

/**
 * Basic example to create a "Hello world" label
 */
extern int monitor_hor_res, monitor_ver_res;
void lv_example_get_started_1(void)
{
    char str[100];
    int len = 0;
    len += sprintf(str + len, "한글 \ncanvas[%d %d]\n", canvas_get_width(), canvas_get_height());
    len += sprintf(str + len, " monitor[%d %d]", monitor_hor_res, monitor_ver_res);
    /*Change the active screen's background color*/
    lv_obj_set_style_bg_color(lv_screen_active(), lv_color_hex(0x003a57), LV_PART_MAIN);

    /*Create a white label, set its text and align it to the center*/
    lv_obj_t * label = lv_label_create(lv_screen_active());
    lv_label_set_text(label, str);
    lv_obj_set_style_text_color(lv_screen_active(), lv_color_hex(0xffffff), LV_PART_MAIN);
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_text_font(label, &NotoSansKR_Regular_28, 0);
}
