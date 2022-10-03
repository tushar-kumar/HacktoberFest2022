class Stack:
    def __init__(self):
        self._items = []
    def length(self):
        return len(self._items)
    def push(self, data):
        self._items.append(data)
    def top(self):
        return self._items[-1]
    def pop(self):
        return self._items.pop()
    def validate(self,x):
      for i in x:
        if i == '(':
          s.push(i)
        elif i == ')':
          if s.length() == 0:
            return False
          else:
            s.pop()
      if s.length() ==0:
        return True
      else:
        return False

postfix =''
s=Stack()
L=['+','-','*','/','^']
x=input("Enter the infix expression: ")
a=s.validate(x)
if a:
  for i in x:
    if i == '(':
      s.push(i)
    elif i ==')':
      while s.top() != '(':
        postfix+=s.pop()
      s.pop()
    elif i in L:
      if s.length()==0:
        s.push(i)
      elif s.top() not in L:
        s.push(i)
      else:
        if L.index(s.top()) > L.index(i):
          while L.index(i) <L.index(s.top()):
            postfix+=s.pop()
            if s.length() == 0:
              s.push(i)
            elif s.top() == '(':
              s.push(i)
            elif L.index(i)==L.index(s.top()):
              s.push(i)
            elif L.index(i)>L.index(s.top()):
              postfix+=s.pop()
              if s.length() == 0:
                s.push(i)
            else:
              s.push(i)
        else:
          s.push(i)
    elif i.isdigit() or i.isalpha():
      postfix+=i
    else:
      postfix=0
      break
  if postfix !=0:
    while s.length()!=0:
      postfix+=s.pop()
    print("THE POSTFIX EXPRESSION IS: ",postfix)
  else:
    print("Incorrect Characters Entered")
else:
  print("Wrong Infix Equation Entered")
