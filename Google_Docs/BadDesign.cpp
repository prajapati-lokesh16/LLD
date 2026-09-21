#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class DocEditor{
    vector<string> elements;
    string renderDocument;

    public:
        void addImage(string img)
        {
            elements.push_back(img);
        }
        void addText(string text)
        {
            elements.push_back(text);
        }
        void saveToFile()
        {
            ofstream file("Document.txt");
            if(file.is_open())
            {
                file << render();
                file.close();
                cout << "Save to file successfully" << endl;
            }
            else{
                cout << "Error in opening the file for writing" << endl;
            }
        }

        string render()
        {
            string result;
            if(renderDocument.empty())
            {
                for(auto element : elements)
                {
                    if(element.size() > 4 && (element.substr(element.size()-4) == ".png" || element.substr(element.size()-4) == ".jpg"))
                    {
                        result += "[Image : " + element + "]" + "\n";
                    }
                    else{
                        result += element + "\n";
                    }
                }
                renderDocument = result;
            }
            return renderDocument;
        }
};

int main()
{
    DocEditor editor;
    editor.addText("Welcome to Google Docs");
    editor.addImage("picture.png");
    editor.addImage("image.jpg");
    cout << editor.render() << endl;
    editor.saveToFile();
}