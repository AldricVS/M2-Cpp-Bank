#if !defined(__EVENT_H__)
#define __EVENT_H__

class Event
{
private:
    double _hour;

public:

    Event();

    ~Event();

    virtual void execute();

    double hour();

};

#endif // __EVENT_H__
