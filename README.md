# Independent Watchdog Driver for STM32


### Functions available

</br>

``` C
int IWDG_Init(int32_t timeout);
void IWDG_Prevent_Reset(void);
void IWDG_Start(void);
```

</br>

### Note: Users are recommended to read through the library. Whenever a command is implemented, IWDG_Prevent_Reset() is to be called to avoid system reset.
