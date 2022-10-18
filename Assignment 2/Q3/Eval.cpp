/*
 * Eval.cpp
 *
 * Description: Evaluation of infix expressions using two Stacks.
 *
 * Author: Rohan Parmar
 * Date: 02/10/2022
 */

#include <iostream>
#include "Scanner.h"
#include "Stack.h" // GENERIC STACK

using namespace std;

int main()
{
    Scanner S(cin);
    Token t;

    Stack<Token> numstack, opstack; // 2x Stacks of type Token

    t = S.getnext();

    while (t.tt != eof || opstack.isEmpty() != true)
    {
        if (t.tt == integer)
        {
            cout << "Pushing " << t.val << " onto numstack" << endl;
            numstack.push(t);
            t = S.getnext();
        }
        else if (t.tt == lptok)
        {
            cout << "Pushing " << t.text << " onto opstack" << endl;
            opstack.push(t);
            t = S.getnext();
        }
        else if (t.tt == rptok)
        {
            if (opstack.peek().tt == lptok)
            {
                cout << "Popping " << opstack.peek().text << " from opstack" << endl;
                opstack.pop();
                t = S.getnext();
            }
            else
            {
                Token op = opstack.pop();
                Token num2 = numstack.pop();
                Token num1 = numstack.pop();
                Token result;
                result.tt = integer;
                if (op.tt == pltok)
                    result.val = num1.val + num2.val;
                else if (op.tt == mitok)
                    result.val = num1.val - num2.val;
                else if (op.tt == asttok)
                    result.val = num1.val * num2.val;
                else if (op.tt == slashtok)
                    result.val = num1.val / num2.val;

                cout << "Pushing " << result.val << " onto numstack" << endl;
                numstack.push(result);
            }
        }
        else if (t.tt == pltok || t.tt == mitok || t.tt == eof)
        {
            if (opstack.isEmpty() != true && (opstack.peek().tt == pltok || opstack.peek().tt == mitok || opstack.peek().tt == asttok || opstack.peek().tt == slashtok))
            {
                Token op = opstack.pop();
                Token num2 = numstack.pop();
                Token num1 = numstack.pop();
                Token result;
                result.tt = integer;
                if (op.tt == pltok)
                    result.val = num1.val + num2.val;
                else if (op.tt == mitok)
                    result.val = num1.val - num2.val;
                else if (op.tt == asttok)
                    result.val = num1.val * num2.val;
                else if (op.tt == slashtok)
                    result.val = num1.val / num2.val;

                cout << "Pushing " << result.val << " onto numstack" << endl;
                numstack.push(result);
            }
            else
            {
                cout << "Pushing " << t.text << " onto opstack" << endl;
                opstack.push(t);
                t = S.getnext();
            }
        }

        else if (t.tt == asttok || t.tt == slashtok)
        {
            if (opstack.isEmpty() != true && (opstack.peek().tt == asttok || opstack.peek().tt == slashtok))
            {
                Token op = opstack.pop();
                Token num2 = numstack.pop();
                Token num1 = numstack.pop();
                Token result;
                result.tt = integer;
                if (op.tt == asttok)
                    result.val = num1.val * num2.val;
                else if (op.tt == slashtok)
                    result.val = num1.val / num2.val;

                cout << "Pushing " << result.val << " onto numstack" << endl;
                numstack.push(result);
            }
            else
            {
                cout << "Pushing " << t.text << " onto opstack" << endl;
                opstack.push(t);
                t = S.getnext();
            }
        }
        else
        {
            cout << "Error: Invalid token: " << t.text << endl;
        }
    }

    cout << "Result: " << numstack.pop().val << endl;

    return 0;
}
