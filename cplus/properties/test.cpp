/*
 * @(#)VM utils.c
 * 
 * @author Mu Li
 */
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>

#include "properties.h"
#include "config.h"

using namespace std;

int main() {

    // loading base config
    Properties config(BASE_CONF_FILE);
    config.load();    
    cout << "Base Config" << endl << config << endl;
    cout << endl;
}