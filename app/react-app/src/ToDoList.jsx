import React, {useState} from 'react'
function ToDoList(){
    const [tasks, setTasks] = useState(["Eat Breakfast","Take a shower","Walk the Dog"]);
    const [newTask, setNewTask] = useState("");

    const handleInputChange = (event) =>{
        setNewTask(n => event.target.value);
    }
    const addTask = () => {
        setTasks(t => [...t, newTask]);
        setNewTask("");
    }
    const deleteTask = (index) => {
        setTasks(tasks.filter((element,i) => i!==index));
    }
    const moveTaskUp = (index) => {
        if(index === 0) return;
        const updatedTasks = [...tasks];
        [updatedTasks[index],updatedTasks[index-1]] = [updatedTasks[index-1],updatedTasks[index]];
        setTasks(updatedTasks);
    }
    const moveTaskDown = (index) => {
        if(index === tasks.length-1) return;
        const updatedTasks = [...tasks];
        [updatedTasks[index],updatedTasks[index+1]] = [updatedTasks[index+1],updatedTasks[index]];
        setTasks(updatedTasks);
    }

    return(
        <div className='to-do-list'>
            <h2>To-Do-List</h2>
            <div className='to-do-list-add-task-div'>
                <input type="text" value={newTask} onChange={handleInputChange} placeholder='Enter a task...'></input>
                <button onClick={addTask} className='to-do-list-add-button'>Add Task</button>
            </div>
                <ol>
                    {tasks.map((task,index) => 
                        <li key={index}>
                            <span className='task-text'>{task}</span>
                            <button className='to-do-list-delete-button' onClick={() => deleteTask(index)}>Delete</button>
                            <button className='to-do-list-move-button' onClick={() => moveTaskUp(index)}>👆</button>
                            <button className='to-do-list-move-button' onClick={() => moveTaskDown(index)}>👇</button>
                        </li>
                    )}
                </ol>            
        </div>
    );
}

export default ToDoList