#ifndef IOEVENT_H
#define IOEVENT_H

class IOEvent
{
    public:
        IOEvent()
        {
            eventType = 0;
            timeStamp = 0;
        }
        int getTime() {return timeStamp;}
        bool getEvent() {return eventType;}
        void setTime(int time) {timeStamp = time;}
        void setType(bool type) {eventType = type;}
    private:
        bool eventType; // 0 user-input 1 hard drive
        int timeStamp; // in time cycles ( just an int )
};
#endif //IOEvent_H
