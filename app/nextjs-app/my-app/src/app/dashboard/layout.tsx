import React from 'react';
import './DashboardLayout.css';

export default function DashboardLayout({
    children,
    users,
    revenue,
    notifications,
} : {
    readonly children: React.ReactNode;
    readonly users: React.ReactNode;
    readonly revenue: React.ReactNode;
    readonly notifications: React.ReactNode;
}) {
    return (
        <>
            <h3>{children}</h3>
            <div className="dashboard-container">
                <div className="card">
                    <div className="card-body">
                        {users}
                    </div>
                </div>
                <div className="card">
                    <div className="card-body">
                        {revenue}
                    </div>
                </div>
                <div className="card">
                    <div className="card-body">
                        {notifications}
                    </div>
                </div>
            </div>
        </>
    );
}
