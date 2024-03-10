#ifndef EXAMPLE_LIST_H
#define EXAMPLE_LIST_H

struct lv_ci_example {
    const char *name;
    void (*fn)(void);
};
void lv_example_get_started_1(void);
void lv_example_get_started_2(void);
void lv_example_event_3(void);
void lv_example_list_2(void);
#endif
