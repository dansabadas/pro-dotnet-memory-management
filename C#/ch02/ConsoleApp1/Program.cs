namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            DoFalseSharingTest(4);
            Console.WriteLine("Hello, World!");
        }
        const int offset = 1;
        const int gap = 0;
        public static int[] sharedData = new int[4 * offset + gap * offset];
        public static long DoFalseSharingTest(int threadsCount, int size =  100_000_000)
        {
            Thread[] workers = new Thread[threadsCount];
            for (int i = 0; i < threadsCount; ++i)
            {
                workers[i] = new Thread(new ParameterizedThreadStart(idx =>
                {
                    int index = (int)idx + gap;
                    for (int j = 0; j < size; ++j)
                    {
                        sharedData[index * offset] = sharedData[index * offset] + 1;
                    }
                }));
            }
            for (int i = 0; i < threadsCount; ++i)
                workers[i].Start(i);
            for (int i = 0; i < threadsCount; ++i)
                workers[i].Join();
            return 0;
        }
    }
}
