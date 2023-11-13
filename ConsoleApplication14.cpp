
#include <iostream>
#include <string>
using namespace std;

class Document {
public:
    string type;
    Document(const string& docType) : type(docType) {}
};

class Handler {

public:
    Handler* nextHandler;

    virtual void processDocument(Document* doc) = 0;

    void setNextHandler(Handler* handler) {
        nextHandler = handler;
    }
};





class TextHandler : public Handler {
public:
    void processDocument(Document* doc) override {
        if (doc->type == "Text") {
           cout << "TextHandler processed the document." << endl;
        }
        else if (nextHandler != nullptr) {
            nextHandler->processDocument(doc);
        }
    }
};

class PDFHandler : public Handler {
public:
    void processDocument(Document* doc) override {
        if (doc->type == "PDF") {
            cout << "PDFHandler processed the document." << endl;
        }
        else if (nextHandler != nullptr) {
            nextHandler->processDocument(doc);
        }
    }


    class ImageHandler : public Handler {
    public:
        void processDocument(Document* doc) override {
            if (doc->type == "Image") {
               cout << "ImageHandler processed the document." << endl;
            }
            else {
                cout << "No handler available for this document type." << endl;
            }
        }
    };

    class TXThadler : public Handler {
    public:
        void processDocument(Document* doc) override {
            if (doc->type == "TXT") {
                cout << "TXT Hadler proccesed the document." << endl;
            }
            else  {
                cout << "No handler available for this document type." << endl;
            
            }

        }

 int main() {
   Document textDocument("Text");
   Document pdfDocument("PDF");
   Document imageDocument("Image");

   Handler* textHandler = new TextHandler();
   Handler* pdfHandler = new PDFHandler();
   Handler* imageHandler = new ImageHandler();

   textHandler->setNextHandler(pdfHandler);
   pdfHandler->setNextHandler(imageHandler);

   textHandler->processDocument(&textDocument);
   textHandler->processDocument(&pdfDocument);
   textHandler->processDocument(&imageDocument);

   delete textHandler;
   delete pdfHandler;
   delete imageHandler;

   return 0;
  }

