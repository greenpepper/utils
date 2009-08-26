/*
 * @(#) Properties.h
 * Java style Properties class declaration
 *
 * @author greenpepper
 */

#ifndef _PROPERTIES_H
#define _PROPERTIES_H

#include "global.h"

#include <map>
#include <string>

using namespace std;

class Properties {
    public:

        Properties(string fn);        

        // accessorial func
        string getFilename();
        void setFilename(string fn);

        // load/save properties from/to files
        void load();
        void load(string fn);
        void save();
        void save(string fn);

        // properties operations
        string get(string key);
        void put(string key, string value);
        void remove(string key);
        void clear();

        // operator overloading
        friend ostream& operator<<(ostream& out, const Properties& prop);

    private:

        map<string, string> propertyMap;
        string fn;
};

#endif  // _PROPERTIES_H
