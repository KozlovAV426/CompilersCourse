# CompilersCourse

Реализация 4-го чекпоинта находится в Types.

## Examples

1. Поддержка скоупов, определение необъявленных или дважды объявленных переменых.

2. Проверка типов при присваиваниях.

```
class SClass {
    public int A() {
        int z;
        int q;
        int[] a;
        q = true;                 // ошибка
        a = new boolean[10];      // ошибка
        z = new int[3];         // ошибка
    }
}
```
Или например,
```
class SClass {
    public boolean A() {
        int z;
        int q;
        int[] a;
        a = new int[10];
    }
}

class TClass {
    public int B() {
        SClass tmp;
        int y;
        y = tmp.A();  // ошибка
    }
}
```

