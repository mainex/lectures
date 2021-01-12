int main() {
    int value = 10, value2 = 20;

    // Технические отличия:
    // 0. Ссылки только в C++, указатели есть и в Си.
    // 1. По-разному объявляются/инициализируются: * и &.
    {
        int *ptr = ...;
        int &ref = ...;
    }
    // 2. По-разному получаем значение:
    {
        int x = *ptr;
        int y = ptr;
    }
    // 3. У указателей есть арифметика: ==, !=, ++, --, +, ....
    // 4. (эзотерика) В системе типов есть указатель на указатель, но не ссылку на ссылку.

    // Содержательные отличия:
    // 5. Ссылку нельзя переприсвоить, а указатель можно.
    //    (но можно завести константный указатель, который тоже нельзя).
    {
        int &ref = value;
        ref = value2;
        // Упс: value == 20.
    }
    // 6. Следствие: ссылку всегда надо проинициализировать.
    // 7. Ссылка всегда куда-то указывает, у указателей есть nullptr.
}
