/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Lista;

import java.util.Date;

/**
 *
 * @author david
 */
public class Tarea {
    private Date start;
    private String name;
    private Boolean status;

    public Tarea(String name) {
        this.name = name;
        this.start = new Date();
        this.status = false;
    }

    /**
     * @return the start
     */
    public Date getStart() {
        return start;
    }

    /**
     * @return the name
     */
    public String getName() {
        return name;
    }

    /**
     * @param name the name to set
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * @return the status
     */
    public Boolean getStatus() {
        return status;
    }

    /**
     * @param status the status to set
     */
    public void setStatus(Boolean status) {
        this.status = status;
    }
    
    
}
