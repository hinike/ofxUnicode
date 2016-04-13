#include "ofxUnicode.h"


//------------------------------------------------------------------
bool ofxUnicode::isValid(const ofUniChar& unichar) {
    return !((unichar > 0x0010ffffu) || (unichar >= 0xd800u && unichar <= 0xdfffu));
}

//------------------------------------------------------------------
bool ofxUnicode::isPrintable(const ofUniChar& unichar) {
    Poco::Unicode::CharacterProperties props;
	Poco::Unicode::properties(unichar, props);
    
    return props.type != Poco::Unicode::UCP_CONTROL;
}

//------------------------------------------------------------------
bool ofxUnicode::isCntrl(const ofUniChar& unichar) {
    // True if unichar is:
    //  - ISO 8-bit control character (U+0000..U+001f and U+007f..U+009f)
    //  - UCP_CONTROL
    //  - UCP_FORMAT (Cf)
    //  - UCP_LINE_SEPARATOR
    //  - UCP_PARAGRAPH_SEPARATOR
    // This definition shared with ICU's isCntrl function 
    // http://icu-project.org/apiref/icu4c/uchar_8h.html#a1295bd387a68fe6df79fedce367c18dd
    

    Poco::Unicode::CharacterProperties props;
	Poco::Unicode::properties(unichar, props);
    
    return props.type == Poco::Unicode::UCP_CONTROL              ||
           props.type == Poco::Unicode::UCP_FORMAT               ||
           props.type == Poco::Unicode::UCP_LINE_SEPARATOR       ||
           props.type == Poco::Unicode::UCP_PARAGRAPH_SEPARATOR;
    
}

//------------------------------------------------------------------
bool ofxUnicode::isTitle(const ofUniChar& unichar) {
    Poco::Unicode::CharacterProperties props;
	Poco::Unicode::properties(unichar, props);
    
    return props.type == Poco::Unicode::UCP_TITLE_CASE_LETTER;
}

//------------------------------------------------------------------
bool ofxUnicode::isSpace(const ofUniChar& unichar) {
    return Poco::Unicode::isSpace(unichar);
}

//------------------------------------------------------------------
bool ofxUnicode::isDigit(const ofUniChar& unichar) {
    return Poco::Unicode::isDigit(unichar);
}

//------------------------------------------------------------------
bool ofxUnicode::isPunct(const ofUniChar& unichar) {
    return Poco::Unicode::isPunct(unichar);
}

//------------------------------------------------------------------
bool ofxUnicode::isAlpha(const ofUniChar& unichar) {
    return Poco::Unicode::isAlpha(unichar);
}

//------------------------------------------------------------------
bool ofxUnicode::isAlphaNumeric(const ofUniChar& unichar) {
    return isAlpha(unichar) || isDigit(unichar);
}

//------------------------------------------------------------------
bool ofxUnicode::isLower(const ofUniChar& unichar) {
    return Poco::Unicode::isLower(unichar);
}

//------------------------------------------------------------------
bool ofxUnicode::isUpper(const ofUniChar& unichar) {
    return Poco::Unicode::isUpper(unichar);
}

//------------------------------------------------------------------
ofUniChar ofxUnicode::toLower(const ofUniChar& unichar) {
    return Poco::Unicode::toLower(unichar);
}

//------------------------------------------------------------------
ofUniChar ofxUnicode::toUpper(const ofUniChar& unichar) {
    return Poco::Unicode::toUpper(unichar);
}

//------------------------------------------------------------------
ofUniChar& ofxUnicode::toLowerInPlace(ofUniChar& unichar) { 
    unichar = toLower(unichar); 
    return unichar;
}
//------------------------------------------------------------------
ofUniChar& ofxUnicode::toUpperInPlace(ofUniChar& unichar) { 
    unichar = toUpper(unichar); 
    return unichar;
}

//------------------------------------------------------------------
ofUniString ofxUnicode::toLower(ofUniString& unichar) {
    ofUniString out;
    ofUniString::iterator it = unichar.begin();
    while(it != unichar.end()) {out.push_back(toLower(*(it++)));}
    return out;
}

//------------------------------------------------------------------
ofUniString ofxUnicode::toUpper(ofUniString& unichar) {
    ofUniString out;
    ofUniString::iterator it = unichar.begin();
    while(it != unichar.end()) {out.push_back(toUpper(*(it++)));}
    return out;
}

//------------------------------------------------------------------
ofUniString& ofxUnicode::toLowerInPlace(ofUniString& unichar) {
    ofUniString::iterator it = unichar.begin();
    while(it != unichar.end()) {toUpperInPlace(*(it++));}
    return unichar;
}

//------------------------------------------------------------------
ofUniString& ofxUnicode::toUpperInPlace(ofUniString& unichar) {
    ofUniString::iterator it = unichar.begin();
    while(it != unichar.end()) {toLowerInPlace(*(it++));}
    return unichar;
}


