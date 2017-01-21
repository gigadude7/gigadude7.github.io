using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(SickWebSyte.Startup))]
namespace SickWebSyte
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}
