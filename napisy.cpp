#include <iostream>
#include <sstream>
#include <vector>
#include <memory>
#include <regex>

//https://www.hackerrank.com/challenges/attribute-parser/problem
//https://regexone.com/lesson

const int MAX_LINE = 200;

struct Atribute {

public:
    Atribute(std::string name, std::string value) : _name(name), _value(value) {};
    void show() const{

        std::cout << _name << " = ";
        std::cout << _value << ", ";

    }


private:
    std::string _name;
    std::string _value;

};

class Tag {

private:
    std::string _name;
    std::vector<std::unique_ptr<Atribute>> atributesVector;

public:
    Tag(std::string name) : _name(name) {};

    void addAtribute(std::string name, std::string value) {

        atributesVector.push_back(std::move(std::make_unique<Atribute>(name, value)));

    }

    void show() const{

        std::cout << _name << " ";

        for (auto &i : atributesVector) {

            i->show();

        }

        std::cout << std::endl;

    }

};

class Analyzer {

private:
        std::vector<std::unique_ptr<Tag>> tagsVector;

public:

    void parseTag(std::string stringToParse) {

        //Gets a line - string and checks for tags

        std::regex tagNameRegex("^<([A-Za-z0-9]+)");
        std::regex tagAtributeRegex("([\\S]+)\\s?=\\s?\\\"([^\\s]+)\\\"");

        std::smatch what;
        std::smatch what2;

        if (std::regex_search(stringToParse, what, tagNameRegex)) {

            std::string name = what[1];

            auto ptr = std::make_unique<Tag>(name);

            //Searching for atributes
            auto words_begin = std::sregex_iterator(stringToParse.begin(), stringToParse.end(), tagAtributeRegex);
            auto words_end = std::sregex_iterator();

            for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
                std::smatch match = *i;
                ptr->addAtribute(match[1], match[2]);
            }

            tagsVector.push_back(std::move(ptr));

        }

    }

    void showTags() const {

        //Shows all the tags on the std::cout

        for (auto& i : tagsVector) {

            i->show();

        }

    }

};

int main() {

    //FIRST LINE INPUT

    int input_count, request_count;

    if (!(std::cin >> input_count) or !(std::cin >> request_count)) {
        throw (std::invalid_argument("Please enter numbers"));
    }

    std::cin.ignore(MAX_LINE, '\n');

    //TAGS INPUT

    std::vector<std::string> tagLinesVector;
    std::vector<std::string> requestLinesVector;

    tagLinesVector.reserve(input_count);
    requestLinesVector.reserve(request_count);

    Analyzer analyzer;

    std::string tmpString;
    for (int i = 0; i < input_count; i++) {
        std::getline(std::cin, tmpString, '\n');
        tagLinesVector.push_back(tmpString);
        analyzer.parseTag(tmpString);
    }

    for (int i = 0; i < request_count; i++) {
        std::getline(std::cin, tmpString, '\n');
        requestLinesVector.push_back(tmpString);
    }

    std::cout << "STWORZONE TAGI:" << std::endl;

    analyzer.showTags();


    //TAGS REQUEST

    return 0;
}

