#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class DocRender{
    public:
    virtual string render() = 0;
};

class TextElement : public DocRender{
    string text;

    public:
        TextElement(string text)
        {
            this->text = text;
        }

        string render() override
        {
            return text;
        }

};

class ImageElement : public DocRender{
    string imgPath;

    public:
        ImageElement(string path)
        {
            this->imgPath = path;
        }

        string render() override
        {
            return "[Image : " + imgPath + " ]";
        }

};

class NewLineElement : public DocRender{
    public:
        string render() override
        {
            return "\n";
        }

};


class DocElements{
    vector<DocRender*> documentElements;

    public:
        void addElement(DocRender* element)
        {
            documentElements.push_back(element);
        }

        string render()
        {
            string result;
            for(auto element : documentElements)
            {
                result += element->render();
            }
            return result;
        }
};

class Persistence{
    public:
        virtual void save(string data) = 0;
};

class FileStorage: public Persistence{
    public:
        void save(string data)
        {
            ofstream outFile("Document.txt");
            if(outFile)
            {
                outFile << data;
                outFile.close();
                cout << "Document saved succesfully" << endl;
            }
            else{
                cout << "Error: Unable to open file for writing"<< endl;
            }
        }
};

class DocumentEditor{
    private:
        DocElements* document;
        Persistence* storage;
        string renderedDocument;

    public:
        DocumentEditor(DocElements* document,Persistence* storage)
        {
            this->document = document;
            this->storage = storage;
        }

        void addText(string text)
        {
            document->addElement(new TextElement(text));
        }
        void addImage(string text)
        {
            document->addElement(new ImageElement(text));
        }

        void addNewline()
        {
            document->addElement(new NewLineElement());
        }

        string renderDocument()
        {
            if(renderedDocument.empty()){
                renderedDocument = document->render();
            }
            return renderedDocument;
        }

        void saveDocument(){
            storage->save(renderDocument());
        }
};

int main()
{
    DocElements* document = new DocElements();
    Persistence* persistence = new FileStorage();
    DocumentEditor* editor = new DocumentEditor(document,persistence);

    editor->addText("Hello World!");
    editor->addNewline();
    editor->addImage("image.png");
    cout << editor->renderDocument()<<endl;
    editor->saveDocument();

    return 0;
}