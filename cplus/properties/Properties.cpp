/*
 * @(#) Properties.cpp
 * Java style Properties class definition
 *
 * @author greenpepper
 */
#include <iostream>
#include <fstream>
#include <iterator>

#include "Properties.h"

/** constructors **/
Properties::Properties(string fn) {
    this->fn = fn;
    load();
}

/** geters & seters **/
string Properties::getFilename() {
    return this->fn;
}

void Properties::setFilename(string fn) {
    this->fn = fn;
}

/** 
 * properties <-> file operations 
 * This implementation is not thread safe
 */
void Properties::load(string fn) {
    // set member variable
    this->fn = fn;

    // load file
    ifstream ifs(this->fn.c_str());
    string line;
    while (getline(ifs, line)) {
        int found = line.find_first_of("=");
        if (found>0) {
            string key = line.substr(0, found);
            string value = line.substr(found+1, line.length()-found);
            this->put(key, value);
        }
    }
    ifs.close();
}
void Properties::load() {
    load(this->fn);
}

void Properties::save(string fn) {

    // set member variable
    this->fn = fn;

    // save properties to file
    ofstream ofs(this->fn.c_str());
    map<string, string>::const_iterator iter;
    for(iter=this->propertyMap.begin(); iter!=this->propertyMap.end(); ++iter) {
        ofs << iter->first << "=" << iter->second << endl;
    }
    ofs.close();

}
void Properties::save() {
    save(this->fn);
}

/** properties operations **/
string Properties::get(string key) {
    return propertyMap[key];
}
void Properties::put(string key, string value) {
    propertyMap[key] = value;    
}
void Properties::remove(string key) {    
    propertyMap.erase(key);
}
void Properties::clear() {
    propertyMap.clear();
}

/** operator overloading **/
ostream& operator<<(ostream& out, const Properties& prop) {

    out << "======= properties =======" << endl;

    // iterator the properties
    map<string, string>::const_iterator iter;
    for(iter=prop.propertyMap.begin(); iter!=prop.propertyMap.end(); ++iter) {
        out << iter->first << " - " << iter->second << endl;
    }

    out << "==========================" << endl;

    return out;
}
