#include "plugin.h"
#include <stdio.h>

static void callback(Plugin* p) {
	printf("Hi from libplug");
}

extern "C" int initplug(Plugin* p) {
	p->printHello = callback;
	return 0;
}
