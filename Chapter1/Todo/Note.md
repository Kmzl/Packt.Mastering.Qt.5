# 第一章笔记
## **Q_OBJECT**
  > The `Q_OBJECT` allows the class to define its own signals/slots and more globally Qt's meta-object system.


## **Signals and slots**
  - A **signal** is a message sent by an object
  - A **slot** is a function that will be called when this signal is triggered
  - The **connect** function specifies which **signal** is linked to which **slot**
  - The **slot** also is a lambda expression.

## **Signals and slots feature**
  - A slot remains an ordinary function
  - A single signal can be linked to different slots
  - A single slot can be called by different linked signals
  - A connection can be made between a signal and a slot form different objects, and even between objects living inside different threads
  - **Signals and slots never return values**
  - A signal can connect to another single

## **Memory manage**
  - The `QObject` class parenting automatically handles object destruction.

## **Qt Tip**
  - Press Shift + F4 in Designer mode to switch between the form editor and the source.

## **C++ Tips**
  - lambda [ capture-list ] (params) -> ret { body }
  - You can capture by copy or reference all variables that are reachable in the function where you define your lambda with the syntax [=] and [&]
  - The `this` variable is a special case of the capture list. You cannot capture it by reference[&this] and the compiiler will warn if you are in this situation: [=, this].
