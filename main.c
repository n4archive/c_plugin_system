#include <stdio.h>
#include "plugin_manager.h"

int main() {
	Plugin* p = loadplug("./libplug.so");
	if (p == NULL)
		return 1;
	p->printHello(p);
	p->destroy();
	return 0;
}

