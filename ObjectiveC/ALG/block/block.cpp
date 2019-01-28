//struct __block_impl {
//    void *isa;
//    int Flags;
//    int Reserved;
//    void *FuncPtr;
//};
//typedef void(*TestBlock)(void);
//
//struct __main_block_impl_0 {
//  struct __block_impl impl;
//  struct __main_block_desc_0* Desc;
//  __main_block_impl_0(void *fp, struct __main_block_desc_0 *desc, int flags=0) {
//    impl.isa = &_NSConcreteStackBlock;
//    impl.Flags = flags;
//    impl.FuncPtr = fp;
//    Desc = desc;
//  }
//};
//static void __main_block_func_0(struct __main_block_impl_0 *__cself) {
//
//        printf("Hello World!\n");
//    }
//
//static struct __main_block_desc_0 {
//  size_t reserved;
//  size_t Block_size;
//} __main_block_desc_0_DATA = { 0, sizeof(struct __main_block_impl_0)};
//int main()
//{
//    TestBlock testBlock = ((void (*)())&__main_block_impl_0((void *)__main_block_func_0, &__main_block_desc_0_DATA));
//    
//    
//    ((void (*)(__block_impl *))((__block_impl *)testBlock)->FuncPtr)((__block_impl *)testBlock);
//    return 0;
//}
//
