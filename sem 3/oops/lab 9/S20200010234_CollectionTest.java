import java.util.*;
class Book{
    int serialNumber;
    String Title;
    String Author;
    String Category;
    public int getSerialNumber() {
        return serialNumber;
    }
    public void setSerialNumber(int serialNumber) {
        this.serialNumber = serialNumber;
    }
    public String getTitle() {
        return Title;
    }
    public void setTitle(String title) {
        Title = title;
    }
    public String getAuthor() {
        return Author;
    }
    public void setAuthor(String author) {
        Author = author;
    }
    public String getCategory() {
        return Category;
    }
    public void setCategory(String category) {
        Category = category;
    }
    public Book(int serialNumber, String title, String author, String category) {
        this.serialNumber = serialNumber;
        Title = title;
        Author = author;
        Category = category;
    }
    @Override
    public String toString() {
        return "Author=" + Author + ", Category=" + Category + ", Title=" + Title + ", serialNumber="
                + serialNumber;
    }
}
class Library{
    Map<Book,Integer> books = new LinkedHashMap<> ();
    public void addBook(Book b1){
        if(this.books.containsKey(b1)){
            this.books.put(b1,books.get(b1) + 1);
        }
        else{
            this.books.put(b1,1);
        }
    }
    public void printBook(){
        System.out.println("ALLbooks:-");
        books.forEach((k,v) -> System.out.println(k.toString()+"\n"+ "Count:"+v));
        System.out.println();
    }
    public void printBook(String c){
        System.out.println("Book by category:-");
        for(Map.Entry<Book,Integer>m : books.entrySet())
        {
            if (c.equals(m.getKey().getCategory())) {
                System.out.println(m.getKey().toString()+"\n"+ "Count:"+m.getValue());
            }
        }
        System.out.println();
    }
    public Book searchBookByTitle(String Title){
        Book ans;
        for(Map.Entry<Book,Integer>m : books.entrySet())
        {
            if (Title.equals(m.getKey().getTitle())) {
                ans=m.getKey();
                return ans;
            }
        }
        return null;
    }
    public Book searchBookByAuthor(String author){
        Book ans;
        for(Map.Entry<Book,Integer>m : books.entrySet())
        {
            if (author.equals(m.getKey().getAuthor())) {
                ans=m.getKey();
                return ans;
            }
        }
        return null;
    }
    public void sortBooks() {

        List<Map.Entry<Book,Integer>> sortlist=new ArrayList<>(this.books.entrySet());
        Collections.sort(sortlist,new Comparator<Map.Entry<Book,Integer>>(){
                @Override
                public int compare(Map.Entry<Book,Integer> b1,Map.Entry<Book,Integer> b2) {
                    if(b1.getKey().getSerialNumber()<b2.getKey().getSerialNumber())
                    return -1;
                    else if(b1.getKey().getSerialNumber()>b2.getKey().getSerialNumber())
                    return 1;
                    else 
                    return 0;

                }
            }
        );
        this.books.clear();
        for (Map.Entry<Book,Integer> m : sortlist) {
            this.books.put(m.getKey(), m.getValue());
        }
    }
}
public class S20200010234_CollectionTest {

    public static void main(String[] args) {
        Book a1 = new Book(69, "Rich dad poor dad", "Robert Kiyosaki", "finance");
        Book a2 = new Book(2, "Da Vinci Code", "Brown", "Crime");
        Book a3 = new Book(10, "Fifty Shades of Grey", "James", "Romance");
        Book a4 = new Book(9, "Angels and Demons", "Dan", "Thriller");
        Book a5 = new Book(9, "Angels and Demons", "Dan", "Thriller");
        // Book a5 = new Book(169, "Twilight", "Meyer", "Fiction");
        Library L = new Library();
        L.addBook(a1);
        L.addBook(a2);
        L.addBook(a3);
        L.addBook(a4);
        L.addBook(a5);
        L.printBook();
        L.sortBooks();
        System.out.println("Sorted books");
        L.printBook();
        L.printBook("Fiction");
        System.out.println("Book searched by Title:-"+L.searchBookByTitle("Angels and Demons"));
        System.out.println();
        System.out.println("Book searched by Author:-"+L.searchBookByAuthor("Brown"));

    }
    
}