# C plugin system
## Build
Main application: `gcc -o app main.c plugin_manager.c -ldl -export-dynamic`
Plugin: `gcc -c libplug.c -o libplug.o -pedantic -g -Wall -std=c99 -fpic -I. && gcc libplug.o -o libplug.so -shared`
