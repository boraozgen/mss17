#### 1. SystemC
**a)**
*sc\_signal* values update after a delta cycle, so at the end
of simulation  
a = 0 + 4 = 4  
b = 0 + 1 = 1 (if t2 executes first), b = 4 + 1 = 5 (if t1 executes first)  
c = 1 + 1 = 2 (if t2 executes first), c = 1 + 2 = 3 (if t1 executes first)  
d = 1 + 4 = 5  
(*SC\_THREADS* will execute until a wait, no context changes in between)

**b)**
```
SC_THREAD(action)
...
void action() {
	while(1) {
		z = x*x + y*y;
		wait(x.value_changed_event() | y.value_changed_event());
	}
}
```

**c)**
```
e.notify();				// trigger executes at 50ns
e.notify(30, SC_NS); // plan trigger at 80ns
e.notify(20, SC_NS); // cancel previous, plan trigger at 70ns
wait(10, SC_NS);		// advance time to 60ns
e.notify(20, SC_NS); // ignored trigger at 80ns
wait(30, SC_NS);		// advance time to 90ns
							// trigger executes at 70ns
e.notify(20, SC_NS);	// plan trigger at 110ns
wait(10, SC_NS);		// advance time to  100ns
e.notify(0, SC_NS);	// cancel previous, plan trigger at 100ns
e.notify(5, SC_NS);	// ignored trigger at 105ns
wait(10, SC_NS);		// advance time to 110ns
							// trigger executes at 100ns
```

50  ns - trigger  
60  ns  
70  ns - trigger  
80  ns  
90  ns  
100 ns - trigger  
110 ns

**d)**  
SystemC built-in channels  
(*sc\_mutex* and *sc\_semaphore* are the other 2 built-in channels)

- *sc\_signal*
	- event when value changes
	- single item can be stored
	- read, write, assignment (=)
- *sc\_buffer*  
	- event when value written (could be the same value)
	- single item can be stored
	- read, write, assignment (=)
- *sc\_fifo*  
	- event when the contents are modified (read or write)
	- size can be defined by the user, default is 16
	- read, write, nb\_read, nb\_write

#### 2. OOP
**a)**

- Class a
	- Attributes
		- b \- private
		- c \- protected
		- d \- public
	- Methods
		- a() \- constructor
		- p() \- private 
		- q(char) \- protected
		- r(int) \- public

- Class b
	- Attributes
		- e \- private
		- f \- protected
		- g \- public
		- c \- inherited from a
		- d \- inherited from a
	- Methods
		- b(b) \- copy constructor
		- r(int) \- overloaded public
		- s(char) \- protected
		- t(int) \- public
		- q(char) \- inherited from a

**b)**

- a() \- constructor
- b(b) \- copy constructor

**c)**

|      | b   | c   | d   | e   | f   | g   | p() | q() | r() | s() | t() |
| ---  | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| o1:a |     |     | X   |     |     |     |     |     | X   |     |     |
| o2:b |     |     | X   |     |     | X   |     |     | X   |     | X   |

**d)**

|      | b   | c   | d   | e   | f   | g   | p() | q() | r() | s() | t() |
| ---  | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| q()  | X   | X   | X   |     |     |     | X   | X   | X   |     |     |
| t()  |     | X   | X   | X   | X   | X   |     | X   | X   | X   | X   |


#### 3. TLM

**a)**
- The functional view:
	- Typically SystemC built-in channels are used as
	  comm. mechanisms
	- comm. is modeled without timing (with delta cycles)

- The programmer's view:
	- bus based comm., no arbitration is modeled

- The architecture view:
	- bus based comm., some arbitration is modeled with mutexes

- The verification view:
	- bus based comm., cycle accurate, all arbitration is modeled

**b)**  

| Initiator             |     | Target                | At         | Sim. time | Lcl offset |
| ---                   | --- | ---                   | ---        | ---       | ---        |
| b\_transport(t, 0ns)  | --> |                       | Initial:   | 0ns       | 0ns        |
|                       | <-- | b\_transport(t, 5ns)  | After ret: | 0ns       | 5ns        |
| b\_transport(t, 20ns) | --> |                       |            |           |            |
|                       | <-- | b\_transport(t, 35ns) | After ret: | 0ns       | 35ns       |
| b\_transport(t, 40ns) | --> |                       | Bef. call: | 0ns       | 40ns       |
|                       |     | wait(40ns)            |            |           |            |
|                       | <-- | b\_transport(t, 5ns)  | After ret: | 40ns      | 5ns        |

