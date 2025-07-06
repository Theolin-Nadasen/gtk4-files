#include <gtk/gtk.h>

void activate(GtkApplication* app, gpointer data){
    GtkWidget* window = gtk_application_window_new(app);

    gtk_window_set_title(GTK_WINDOW(window), "my test app");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char** argv)
{
    GtkApplication* myapp = gtk_application_new("com.theo.test", G_APPLICATION_DEFAULT_FLAGS);
    int status;

    g_signal_connect(G_APPLICATION(myapp), "activate", G_CALLBACK(activate), NULL);

    status = g_application_run(G_APPLICATION(myapp), argc, argv);


    g_object_unref(myapp);

    return status;
}
