#include<iostream>
#include"../lib/EventEmitter.hpp"

void a (){
    std::cout<<"EVENT EMITTED";
}

int main() {
    EventEmitter emitter;

    // Subscribe to an event
    emitter.on("exampleEvent", a);

    // Emit the event
    emitter.emit("exampleEvent");

    // Unsubscribe from the event
    emitter.off("exampleEvent", a);

    // Emit the event again (no subscribers left)
    emitter.emit("exampleEvent");

    return 0;
}