public class Main {
    public static void main(String[] args) {
        int length;
        int[] array = new int[100];
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        length = scanner.nextInt();

        for (int i = 0; i < length; i++) {
            array[i] = scanner.nextInt();
        }
        
        insertionSort(array, length);
        printArray(array, length);
    }

    private static void insertionSort(int[] array, int length) {
        for (int i = 1; i < length; i++) {
            int buf = array[i];
            int j = i - 1;

            printArray(array, length);

            while (j >= 0 && array[j] > buf) {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = buf;
        }
    }

    private static void printArray(int[] array, int length) {
        for (int i = 0; i < length; i++) {
            if (i != 0) System.out.print(" ");
            System.out.print(array[i]);
        }
        System.out.println();
    }
}
