#ifndef PLUGIN_H
#define PLUGIN_H
struct _Plugin {
	void (*printHello) (struct _Plugin*);
	void* __libhandle;
};
typedef struct _Plugin Plugin;
#endif
