#ifndef PLUGIN_H
#define PLUGIN_H
struct _Plugin {
	void (*printHello) (struct _Plugin*);
	void (*destroy)();
};
typedef struct _Plugin Plugin;
#endif
