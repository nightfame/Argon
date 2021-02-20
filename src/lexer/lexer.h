#ifndef LEXER_H
#define LEXER_H

#include <vector>
#include <iostream>  

using namespace std;

enum class TokenType {
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,

    LPAREN,
    RPAREN,

    NUMBER, 
    WORD,

    POINT,

    UNKNOWN
};

class Token {
public:
    int num = 0;
    string word;
    TokenType type;

    Token(TokenType type);
    Token(TokenType type, int num);
    Token(TokenType type, string word);
};

class Lexer {
    string word;
    int number = 0;
    bool parsing_word = false;
    bool parsing_number = false;

    void make_cases(char subject);
public:
    vector<Token> tokens;

    Lexer(string content);
    vector<Token> get_tokens();
};

#endif