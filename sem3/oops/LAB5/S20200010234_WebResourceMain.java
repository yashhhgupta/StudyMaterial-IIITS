class WebResouce{
    String domainName;
    String pathToResouce;
    String nameOfResouce;
    public WebResouce(String domainName, String pathToResouce,String nameOfResouce){
        this.domainName = domainName;
        this.pathToResouce = pathToResouce;
        this.nameOfResouce = nameOfResouce;
    }
    public String getDomainName() {
        return domainName;
    }
    public void setDomainName(String domainName) {
        this.domainName = domainName;
    }
    public String getPathToResouce() {
        return pathToResouce;
    }
    public void setPathToResouce(String pathToResouce) {
        this.pathToResouce = pathToResouce;
    }
    public String getNameOfResouce() {
        return nameOfResouce;
    }
    public void setNameOfResouce(String nameOfResouce) {
        this.nameOfResouce = nameOfResouce;
    }
    public String getFullURL() {
        return ("http://www."+this.domainName+this.pathToResouce+"/"+this.nameOfResouce);
    }
}
class SecureWebResource extends WebResouce{
    public SecureWebResource(String domainName, String pathToResouce,String nameOfResouce){
        super(domainName, pathToResouce, nameOfResouce);
    }
    public String getFullURL() {
        return ("https://www."+this.domainName+this.pathToResouce+"/"+this.nameOfResouce);
    }
}
class DynamicWebResource extends WebResouce{
    String servletName;
    String jspTemplate;
    public DynamicWebResource(String domainName, String pathToResouce,String nameOfResouce,String servletName,String jspTemplate){
        super(domainName, pathToResouce, nameOfResouce);
        this.servletName = servletName;
        this.jspTemplate = jspTemplate;
    }
    public String getServletName() {
        return servletName;
    }
    public void setServletName(String servletName) {
        this.servletName = servletName;
    }
    public String getJspTemplate() {
        return jspTemplate;
    }
    public void setJspTemplate(String jspTemplate) {
        this.jspTemplate = jspTemplate;
    }
    public String getFullURL() {
        return ("http://www."+this.domainName+this.pathToResouce+"/"+this.servletName.replace(".","/"));
    }
}
class SecureDynamicWebResource extends DynamicWebResource{
    public SecureDynamicWebResource(String domainName, String pathToResouce,String nameOfResouce,String servletName,String jspTemplate){
        super(domainName, pathToResouce, nameOfResouce,servletName, jspTemplate);
    }
    public String getFullURL() {
        return ("https://www."+this.domainName+this.pathToResouce+"/"+this.servletName.replace(".","/"));
    }
} 
public class S20200010234_WebResourceMain {
    public static WebResouce[] links =new WebResouce[10];
    public static void printAllWebResouceURL(int n){
        for (int i = 0; i < n; i++) {
            System.out.println(links[i].getFullURL());
        }
    }
    public static void main(String[] args){
        String domainName="build-your-website.co.uk";
        String pathToResouce="/html";
        String nameOfResouce="indix.htm";
        String servletName="org.iiits.IndexServlet";
        String jspTemplate="org.iiits.IndexTemplate.jsp";
        WebResouce web =new WebResouce(domainName, pathToResouce, nameOfResouce);
        SecureWebResource Sweb =new SecureWebResource(domainName, pathToResouce, nameOfResouce);
        DynamicWebResource Dweb=new DynamicWebResource(domainName,"","",servletName,jspTemplate);
        SecureDynamicWebResource Sdweb=new SecureDynamicWebResource(domainName,"","",servletName,jspTemplate);
        links[0]=web;
        links[1]=Sweb;
        links[2]=Dweb;
        links[3]=Sdweb;
        printAllWebResouceURL(4);
    }
    
}
