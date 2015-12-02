using System;
using System.Collections.Generic;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Text.RegularExpressions;
using System.Net;
using System.Text;

public partial class _Default : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
   
    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        string htmlcode = GetHTML("http://www.baidu.com/s?wd=K8%BB%FA%C6%F7%C8%CB");//K8机器人
      
        Regex reg= new Regex("<table cellpadding=\"0\".*href=\"(?<k8url>.+).*target=\"_blank\">(?<k8title>.+)"); 

        MatchCollection ms = reg.Matches(htmlcode); 
        foreach (Match m in ms)
        {
            //this.Response.Write(m.Groups["k8url"]+" " + m.Groups["k8title"] + "<br>");  
            this.Response.Write("<a href=\"" + m.Groups["k8url"] + "\">" + m.Groups["k8title"] + "</a><br>");
        }
    }

    public string GetHTML(string url)
    {
        WebClient web = new WebClient();
        byte[] buffer = web.DownloadData(url);
        return Encoding.Default.GetString(buffer);
    }
}
