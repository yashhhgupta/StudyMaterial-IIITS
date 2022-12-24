public class StackMain {

    public static void push(float[] temp, int index, float data) {
        temp[index] = data;
    }

    public static void pop(float[] temp, int index) {
        float val = temp[index];
    }

    public static void display(float[] temp, int index) {
        for (int i = 0; i <= index; i++) {
            System.out.printf("%.1f ", temp[i]);
        }
        System.out.println();
    }

    public static void copy(float[] temp1, float[] temp2, int size) {
        for (int i = 0; i <= size; i++) {
            temp2[i] = temp1[i];
        }
    }

    public static void main(String[] args) {
        float[] stack1 = new float[100];
        float[] stack2 = new float[100];
        int top1 = -1, top2 = -1;
        int operation[] = { 1, 1, 1, 2, 1, 2, 3, 4 };
        float input[] = { 2.1f, 2.2f, 2.3f, 0f, 2.4f, 0f, 0f, 0f };
        int j = 0;
        for (int i = 0; i < operation.length; i++) {
            switch (operation[i]) {
                case 1: {
                    if (top1 == 100) {
                        System.out.println("Stack1 is full");
                        continue;
                    }
                    top1++;
                    j++;
                    push(stack1, top1, input[j]);
                    break;
                }
                case 2: {
                    if (top1 == -1) {
                        System.out.println("Stack is empty");
                    } else {
                        pop(stack1, top1);
                        top1--;
                    }
                    break;
                }
                case 3: {
                    copy(stack1, stack2, top1);
                    top2 = top1;
                    break;
                }
                case 4: {
                    display(stack1, top1);
                    display(stack2, top2);
                    break;
                }
                default :{
                    System.out.println("Operation not valid");
                }
            }
        }

    }
}