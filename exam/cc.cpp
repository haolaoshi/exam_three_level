

class String
{
public:
    String(const char* src = NULL);
    String(const String& other);
    ~String(void);
    String& operator=(const String &other);
private:
    char *m_data;
};

String::String(const char* src = NULL)
{
    if(src == NULL)
        return;

    if(m_data != NULL)
        delete []m_data;

    m_data = new char[strlen(src)]; 
    strcpy(m_data,src);
}

String::String(const String& other)
{
    if(other == this)
        return;
    
    if(m_data != NULL)
        delete m_data;
  
}

String::~String()
{
    if(m_data != NULL)
        delete m_data;
    m_data = NULL;
}

String& 
String::operator=(const String& other)
{



}
