              else if (op.Top() != '(' && priorityOperator(infix[i]) <= priorityOperator(op.Top())) {
                    postfix[np++] = op.Top();
                    op.Pop();
                    op.Push(infix[i]);
                } else op.Push(infix[i]);
            }
        }
    }
    while (!op.Empty()) {
        if (op.Top() != '(') postfix[np++] = op.Top();
        op.Pop();
    }
}
