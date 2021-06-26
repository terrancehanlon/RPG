#ifndef TEXTMANAGER_H
#define TEXTMANGER_H

#include <string>
#include "./Imports.h"

#include <vector>

struct TextItem {
    std::string text;
    std::string key;
};

class TextManager {

    public:
        void addText(const std::string& key, const std::string& text);
        const std::string& getText(const std::string& key); //get text


        TextManager();
    private:
        std::vector<TextItem> texts;


};

#endif