#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/timer.h>

#define TAG "week10 laboratory"

static struct timer_list mytimer;


void exampleTimerFunc(struct timer_list *t) {
   printk(KERN_INFO "My timer has been executed!\n");
   time_t timer;
   char buffer[26];
   struct tm* tm_info;

   timer = time(NULL);
   tm_info = localtime(&timer);

   strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);

   printk("The date is %d\n", buffer)
}

void exampleWithTimer(void) {

   printk( "Starting timer to fire in 3s (%ld)\n", jiffies );
   mytimer.expires = jiffies + msecs_to_jiffies(3000);
   timer_setup(&mytimer, exampleTimerFunc, 0);

   add_timer(&mytimer);
}

int init_module(void) {
   printk(KERN_INFO "Starting %s\n", TAG);
   exampleWithTimer();
   return 0;
}

void cleanup_module(void) {
   printk(KERN_INFO "Cleanup %s\n", TAG);
   del_timer(&mytimer);
}
