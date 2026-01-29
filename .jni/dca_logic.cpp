#include <iostream>
#include <pthread.h>
#include <dlfcn.h>
#include <unistd.h>
#include <string.h>

int (*orig_pthread_create)(pthread_t*, const pthread_attr_t*, void* (*)(void*), void*);

int hooked_pthread_create(pthread_t* thread, const pthread_attr_t* attr, void* (*start_routine)(void*), void* arg) {
    Dl_info info;
    if (dladdr((void*)start_routine, &info)) {
        if (info.dli_fname && (strstr(info.dli_fname, "libanogs.so") || strstr(info.dli_fname, "libGCloud.so"))) {
            return 0; 
        }
    }
    return orig_pthread_create(thread, attr, start_routine, arg);
}

int main() {
    printf("DCA_BYPASS: Stealth Logic Initialized\n");
    while(true) { sleep(10); }
    return 0;
}
