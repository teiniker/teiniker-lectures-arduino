# Cyclic Processing

In many programmable logic controllers (PLC) a **cyclic program processing** 
will be used - the program is processed in **fixed cycles**.

A processing cycle usually consists of: 
1. **Reading inputs**: Read digital or analog pins into variables.
2. **Outputting results**: Write digital or analog pins from pre-calculated 
  variables.
3. **Sequentially processing program commands**: Execute the control logic 
  using these variables.

Cyclic processing, where signals are read, processed, and outputs are updated 
at fixed, deterministic time intervals, is fundamental to **signal processing** 
and **control algorithms** for several key reasons:

* **Predictable Timing and Determinism**:
  - Control and signal-processing algorithms are designed assuming a constant 
    sampling period.
  - Fixed intervals guarantee deterministic behavior, which is essential in 
    real-time systems.
  - Variable execution timing introduces jitter, leading to inconsistent results.

* **Correct Mathematical Modeling**: 
  - Digital signal processing (DSP) and control theory rely on 
    **discrete-time models**.
  - These models assume signals are sampled at uniform intervals.
  - If the sampling interval changes, the model assumptions are violated, 
    degrading performance or causing instability.

* **Stability of Control Systems**:
  - Controllers (e.g., PID, state-space controllers) are tuned for a specific 
    sampling period.
  - Irregular timing can:
    - Alter effective controller gains
    - Reduce phase margin
    - Cause oscillations or **instability**

* **Accurate Signal Reconstruction and Filtering**: 
  - **Digital filters** depend on a fixed sampling frequency.
  - Non-uniform sampling:
    - Distorts frequency response
    - Breaks filter characteristics (cutoff frequency, attenuation)
  - Fixed intervals help **avoid aliasing-related artifacts**.



## Example: Cyclic Processing 

```C
void loop() 
{
  // Cycle Time Scheduler 
  while(millis() < timestamp + CYCLE_TIME);  
  timestamp = millis();

  // IO (read and write)
  digitalWrite(LED1_PIN, led1_flag ? HIGH : LOW);
  digitalWrite(LED2_PIN, led2_flag ? HIGH : LOW);
       
  // Control Logic
  led1_flag = !led1_flag; 
  if(counter < 4)
  {
    counter++;
  }
  else
  {
      counter = 0;
      led2_flag = !led2_flag; 
  }
}
```
Note that in order to be able to read and write IO pins at precisely defined intervals, their 
values must be temporarily stored in varibles.


## Example: Simple Task Scheduler

If we want to carry out several tasks (for example blinking LEDs) at the same time, 
we can **define different intervals** and timestams. 
We call such a structure a simple **task scheduler**.


```C
void loop() 
{
  // Task 1
  if(millis() >= timestamp_1 + INTERVAL_1)
  {
      timestamp_1 = millis();
      digitalWrite(LED1_PIN, !digitalRead(LED1_PIN));
  }

  // Task 2
  if(millis() >= timestamp_2 + INTERVAL_2)
  {
      timestamp_2 = millis();
      digitalWrite(LED2_PIN, !digitalRead(LED2_PIN));
  }
  //...
}
```
With this construct it should be noted that the **tasks must not take longer 
than the shortest interval**. Otherwise the timing is no longer right.

If the implementation of the individual tasks get more complex, it makes 
sense to implement independent **task() functions** which are called by 
the scheduler.

```C
void loop() 
{
  if(millis() >= timestamp_1 + INTERVAL_1)
  {
      timestamp_1 = millis();
      task_1();
  }

  if(millis() >= timestamp_2 + INTERVAL_2)
  {
      timestamp_2 = millis();
      task_2();
  }

  //...
}

void task_1(void) // INTERVAL_1
{
   digitalWrite(LED1_PIN, !digitalRead(LED1_PIN));
}

void task_2(void) // INTERVAL_2
{
   digitalWrite(LED2_PIN, !digitalRead(LED2_PIN));
}
```

_Example:_ TinkerCAD - [Blink Scheduler](https://www.tinkercad.com/things/hBWwhvLwV6O)


## References 

* [Scan time of the PLC program](https://www.plcacademy.com/scan-time-of-the-plc-program/) 


*Egon Teiniker, 2020-2025, GPL v3.0* 