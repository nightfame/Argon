#include "lexer.h"

// some overloads
Token::Token(TokenType type): type(type) { }
Token::Token(TokenType type, int num): type(type), num(num) { }
Token::Token(TokenType type, string word): type(type), word(word) { }

Lexer::Lexer(string content) {
    for(int i = 0; i < content.length(); i++) {
        make_cases(content[i]);
    }
    if(lparen_count != rparen_count)
        throw runtime_error("lparen count != rparen count");
}

vector<Token> Lexer::get_tokens() {
    return tokens;
}

void Lexer::make_cases(char subject) {
    switch (subject)
    { // TODO make case macros
    case '+':
        if(parsing_number) {
            tokens.push_back(Token(TokenType::NUMBER, number));
            parsing_number = false;
            number = 0;
        }
        if(parsing_word) {
            tokens.push_back(Token(TokenType::WORD, word));
            parsing_word = false;
            word = "";
        }
        tokens.push_back(Token(TokenType::PLUS));
        break;
    case '-':
        if(parsing_number) {
            tokens.push_back(Token(TokenType::NUMBER, number));
            parsing_number = false;
            number = 0;
        }
        if(parsing_word) {
            tokens.push_back(Token(TokenType::WORD, word));
            parsing_word = false;
            word = "";
        }
        tokens.push_back(Token(TokenType::MINUS));
        break;
    case '*':
        if(parsing_number) {
            tokens.push_back(Token(TokenType::NUMBER, number));
            parsing_number = false;
            number = 0;
        }
        if(parsing_word) {
            tokens.push_back(Token(TokenType::WORD, word));
            parsing_word = false;
            word = "";
        }
        tokens.push_back(Token(TokenType::MULTIPLY));
        break;
    case '/':
        if(parsing_number) {
            tokens.push_back(Token(TokenType::NUMBER, number));
            parsing_number = false;
            number = 0;
        }
        if(parsing_word) {
            tokens.push_back(Token(TokenType::WORD, word));
            parsing_word = false;
            word = "";
        }
        tokens.push_back(Token(TokenType::DIVIDE));
        break;
    case '.':
        if(parsing_number) {
            tokens.push_back(Token(TokenType::NUMBER, number));
            parsing_number = false;
            number = 0;
        }
        if(parsing_word) {
            tokens.push_back(Token(TokenType::WORD, word));
            parsing_word = false;
            word = "";
        }
        tokens.push_back(Token(TokenType::POINT));
        break;
    case '(':
        if(parsing_number) {
            tokens.push_back(Token(TokenType::NUMBER, number));
            parsing_number = false;
            number = 0;
        }
        if(parsing_word) {
            tokens.push_back(Token(TokenType::WORD, word));
            parsing_word = false;
            word = "";
        }
        tokens.push_back(Token(TokenType::LPAREN));
        lparen_count++;
        break;
    case ')':
        if(parsing_number) {
            tokens.push_back(Token(TokenType::NUMBER, number));
            parsing_number = false;  
            number = 0;
        }
        if(parsing_word) {
            tokens.push_back(Token(TokenType::WORD, word));
            parsing_word = false;
            word = "";
        }
        tokens.push_back(Token(TokenType::RPAREN));
        rparen_count++;
        break;
    default:
        const char subj_to_str[] = {subject, '\0'}; // stoi takes C-string or std::string, no char
        int subj_as_num = 0;
        try {
            subj_as_num = stoi(subj_to_str);
        }
        catch(invalid_argument) { 
            parsing_word = true;
            word += subject; 
            break;
        }
        parsing_number = true;
        number = (number * 10) + subj_as_num;
        break;
    }
}
