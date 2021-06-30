#include "TextManager.h"
#include <iostream>
TextManager::TextManager(){}

void TextManager::addText(const std::string& key, const std::string& text){
    TextItem t = {
        .text = text,
        .key = key
    };

    texts.push_back(t);
};


const std::string& TextManager::getText(const std::string& key){
    for(auto& t : texts){
        if(t.key == key){
            return t.text;
        }
    }
}